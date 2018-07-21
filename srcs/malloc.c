#include "ft_malloc.h"

size_t			get_size_page(size_t size_requested, int8_t zone)
{
	size_t		size_zone;

	if (zone == 0)
		size_zone = TINY;
	else if (zone == 1)
		size_zone = SMALL;
	else
		size_zone = size_requested;
	if (size_zone % (sizeof(uintptr_t) * 2) > 0)
		size_zone = (size_zone / (sizeof(uintptr_t) * 2) + 1) * (sizeof(uintptr_t) * 2);
	if (zone < 2)
		return (((size_zone * 100 + sizeof(t_block_mem) * 100) / getpagesize() + 1) * getpagesize());
	return (((size_zone + sizeof(t_block_mem)) / getpagesize() + 1) * getpagesize());
}

int8_t			get_zone(size_t size_requested) {
	if (size_requested <= TINY)
		return 0;
	if (size_requested <= SMALL)
		return 1;
	return 2;
}

void			set_metadata(t_block_mem *mem, size_t size_requested, t_block_mem *next_block) {
	mem->size = size_requested;
	mem->used = 1;
	mem->new_page = 0;
	mem->next = next_block;
}

void			set_metadata_next_block(t_block_mem *mem, t_block_mem *next_block) {
	mem->next = next_block;
}


void			*request_memory(size_t size_requested, int8_t zone) {
	size_t		size_malloc;

	size_malloc = get_size_page(size_requested, zone);
	return mmap(0, size_malloc, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

void			*create_new_page(size_t size_requested, int8_t zone)
{
	void		*new_page;
	t_block_mem	*mem;

	new_page = request_memory(size_requested, zone);
	if (new_page == MAP_FAILED)
		return (NULL);
	set_metadata((t_block_mem*)new_page, size_requested, NULL);
	mem = (t_block_mem*)new_page;
	mem->new_page = 1;
	return (new_page);
}

void			*find_next_mem_large(t_block_mem *mem, size_t size_requested) {
	void		*new_alloc_large;
	t_block_mem	*before;

	while (mem != NULL)
	{
		before = mem;
		mem = mem->next;
	}
	new_alloc_large = create_new_page(size_requested, 2);
	set_metadata_next_block(before, (t_block_mem *)new_alloc_large);
	return (new_alloc_large);
}

void			*find_next_mem_tn_sm(t_block_mem *mem, size_t size_requested, int8_t zone) {
	void			*next_alloc;
	t_block_mem		*before;
	t_block_mem		*new_space_free;
	size_t			size_page;
	size_t			size_used_total;

	size_page = get_size_page(0, zone);
	before = mem;
	size_used_total = mem->size + sizeof(t_block_mem);
	mem = mem->next;
	while (mem != NULL)
	{
		if (mem->new_page == 1)
			size_used_total = 0;
		if (mem->used == 0) {
			// Trying to refill hole left by free for new malloc
			if (mem->size >= size_requested)
			{
				mem->used = 1;
				if (mem->size >= size_requested + sizeof(t_block_mem)) // if we have space enough to create free page after the part reuse of this one
				{
					new_space_free = (t_block_mem*)((void *)mem + sizeof(t_block_mem) + size_requested);
					// // print_debugf_size_t(size_requested, "Size requested");
					// // print_debugf_addr((void *)mem, "Addr hole");
					// // print_debugf_size_t(mem->size, "Size free");
					// // print_debugf_size_t(mem->size - (size_requested + sizeof(t_block_mem)), "new space free size");
					set_metadata(new_space_free, mem->size - (sizeof(t_block_mem) + size_requested), mem->next);
					set_metadata_next_block(mem, new_space_free);
					new_space_free->used = 0;
					mem->size = size_requested;
				}
				return ((void*)mem);
			}
		}
		size_used_total += mem->size + sizeof(t_block_mem);
		before = mem;
		mem = mem->next;
	}
	if (size_used_total + size_requested + sizeof(t_block_mem) > size_page)
	{
		// ft_putstr("Creation of new page and return ptr on free space\n");
		next_alloc = create_new_page(size_requested, zone);
		set_metadata_next_block(before, (t_block_mem *)next_alloc);
		return (next_alloc);
	}
	next_alloc = (void *)before + sizeof(t_block_mem) + before->size;
	// continue on page
	set_metadata((t_block_mem*)next_alloc, size_requested, NULL);
	set_metadata_next_block(before, (t_block_mem*)next_alloc);
	return (next_alloc);
}


void	print_debug_size_t(size_t debug, char *name) {
	if (DEBUG == 1)
	{
		ft_putstr("Debug: ");
		ft_putstr(name);
		ft_putstr(" = ");
		print_size(debug);
		ft_putstr("\n");
	}
}

void	print_debug_addr(void *debug, char *name) {
	if (DEBUG == 1)
	{
		ft_putstr("Debug: ");
		ft_putstr(name);
		ft_putstr(" = 0x");
		print_addr(debug);
		ft_putstr("\n");
	}
}

void			*start_malloc(size_t size)
{
	void			*alloc_requested;
	t_block_mem		**mem;
	int8_t			zone;

 	// https://stackoverflow.com/questions/227897/how-to-allocate-aligned-memory-only-using-the-standard-library
	pthread_mutex_lock(&g_mutex);
	if (size % (sizeof(uintptr_t) * 2) > 0)
		size = (size / (sizeof(uintptr_t) * 2) + 1) * (sizeof(uintptr_t) * 2);
	// print_debugf_size_t(size, "Malloc size");
	zone = get_zone(size);
	mem = &g_mem[zone];
	if (*mem == NULL)
	{
		alloc_requested = create_new_page(size, zone);
		*mem = (t_block_mem*)alloc_requested;
	}
	else
	{
		if (zone != 2)
			alloc_requested = find_next_mem_tn_sm(*mem, size, zone);
		else
			alloc_requested = find_next_mem_large(*mem, size);
	}
	print_debug_addr(alloc_requested + sizeof(t_block_mem), "Malloc ptr return");
	pthread_mutex_unlock(&g_mutex);
	if (alloc_requested == NULL)
		return (NULL);
	// print_debugf_size_t((size_t)alloc_requested % 16, "Address return multiple ? -> ");
	return (alloc_requested + sizeof(t_block_mem));
}

void			*malloc(size_t size) {
	void		*ptr;

	// write(1, "MALLOC CALLED\n", 14);
	ptr = start_malloc(size);
	// write(1, "MALLOC END\n", 11);
	return (ptr);
}
