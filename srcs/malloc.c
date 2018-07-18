#include "ft_malloc.h"

int8_t			get_zone(size_t size_requested) {
	// ft_putstr("Comparing: ");
	// print_size((size_requested * 100) + sizeof(t_block_mem));
	// ft_putstr(" AND ");
	// print_size(TINY * (size_t)getpagesize());
	// ft_putstr("\n");

	if (size_requested <= TINY)
		return 0;
	if (size_requested <= SMALL)
		return 1;
	return 2;
}



void			set_metadata(t_block_mem *mem, size_t size_requested, t_block_mem *prev_block, t_block_mem *next_block) {
	mem->size = size_requested;
	mem->used = 1;
	mem->prev = prev_block;
	mem->next = next_block;

	// ft_putstr("SET METADATA : 0x");
	// print_addr((void *)mem);
	// ft_putstr(" ---> ");
	// print_size(mem->size);
	// ft_putstr("\n");
}

void			set_metadata_next_block(t_block_mem *mem, t_block_mem *next_block) {
	mem->next = next_block;
}

void			set_metadata_prev_block(t_block_mem *mem, t_block_mem *prev_block) {
	mem->prev = prev_block;
}


void			*request_memory(size_t size_requested, int8_t zone) {
	size_t		size_malloc;

	if (zone == 0)
		size_malloc = (((TINY * 100) + (sizeof(t_block_mem) * 100)) / getpagesize() + 1) * getpagesize();
	else if (zone == 1)
		size_malloc = (((SMALL * 100) + (sizeof(t_block_mem) * 100)) / getpagesize() + 1) * getpagesize();
	else
		size_malloc = ((size_requested + sizeof(t_block_mem)) / getpagesize() + 1) * getpagesize();
	return mmap(0, size_malloc, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

void			*create_new_page(size_t size_requested, int8_t zone, t_block_mem *prev)
{
	void		*new_page;
	t_block_mem	*mem;

	new_page = request_memory(size_requested, zone);
	if (new_page == MAP_FAILED)
		return (NULL);
	set_metadata((t_block_mem*)new_page, size_requested, prev, NULL);
	mem = (t_block_mem*)new_page;
	mem->new_page = 1;
	return (new_page);
}

void			*find_next_mem_large(t_block_mem *mem, size_t size_requested) {
	void		*ptr;
	t_block_mem	*before;

	while (mem != NULL)
	{
		before = mem;
		mem = mem->next;
	}
	ptr = create_new_page(size_requested, 2, before);
	set_metadata_next_block(before, (t_block_mem *)ptr);
	return (ptr);
}

void			*find_next_mem_tn_sm(t_block_mem *mem, size_t size_requested, int8_t zone) {
	t_block_mem		*before;
	t_block_mem		*new_space_free;
	size_t			size_page;
	size_t			size_used_total;

	if (zone == 0)
		size_page = (((TINY * 100) + (sizeof(t_block_mem) * 100)) / getpagesize() + 1) * getpagesize();
	else
		size_page = (((SMALL * 100) + (sizeof(t_block_mem) * 100)) / getpagesize() + 1) * getpagesize();
	before = mem;
	size_used_total = mem->size + sizeof(t_block_mem);
	mem = mem->next;
	while (mem != NULL)
	{
		if (mem->new_page == 1)
		{
			size_used_total = 0;
		}
		if (mem->used == 0) {
			// ft_putstr("Trying to refill hole left by free for new malloc\n");
			write(1, "REUSE OF HOLE\n", 14);
			if (mem->size >= size_requested)
			{
				mem->used = 1;
				if (mem->size >= size_requested + sizeof(t_block_mem)) // if we have space enough to create free page after the part reuse of this one
				{
					new_space_free = (void *)mem + sizeof(t_block_mem) + size_requested;
					set_metadata(new_space_free, mem->size - (size_requested + sizeof(t_block_mem)), (void *)mem, mem->next);
					set_metadata_next_block(mem, new_space_free);
					mem->size = size_requested;
					new_space_free->used = 0;
				}
				return ((void*)mem);
			}
		}
		size_used_total += mem->size + sizeof(t_block_mem);
		before = mem;
		mem = mem->next;
	}
	print_debug_size_t(size_page, "SIZE PAGE");
	print_debug_size_t(size_used_total, "SIZE TOTAL");

	if (size_used_total + size_requested + sizeof(t_block_mem) > size_page)
	{
		// ft_putstr("Creation of new page and return ptr on free space\n");
		void *ptr = create_new_page(size_requested, zone, before);
		set_metadata_next_block(before, (t_block_mem *)ptr);
		return (ptr);
	}
	// print_debug_size_t(size_used_total + sizeof(t_block_mem) + size_requested, "size_used_total");
	set_metadata((t_block_mem*)(((void *)before) + (sizeof(t_block_mem) + before->size)), size_requested, before, NULL);
	set_metadata_next_block(before, (t_block_mem*)(((void *)before) + (sizeof(t_block_mem) + before->size)));
	return (((void *)before) + (sizeof(t_block_mem) + before->size));
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

	print_debug_size_t(size, "Malloc size");
	zone = get_zone(size);
	mem = &g_mem[zone];
	if (*mem == NULL)
	{
		alloc_requested = create_new_page(size, zone, NULL);
		*mem = (t_block_mem*)alloc_requested;
	}
	else
	{
		if (zone != 2)
			alloc_requested = find_next_mem_tn_sm(*mem, size, zone);
		else
			alloc_requested = find_next_mem_large(*mem, size);
	}
	if (alloc_requested == NULL)
		return (NULL);
	print_debug_addr(alloc_requested + sizeof(t_block_mem), "Malloc ptr return");

	return (alloc_requested + sizeof(t_block_mem));
}

void			*malloc(size_t size) {
	void		*ptr;

	pthread_mutex_lock(&g_mutex);
	ptr = start_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
