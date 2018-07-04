#include "ft_malloc.h"

int8_t			get_zone(size_t size_requested) {
	// ft_putstr("Comparing: ");
	// printsize((size_requested * 100) + sizeof(t_block_mem));
	// ft_putstr(" AND ");
	// printsize(TINY * (size_t)getpagesize());
	// ft_putstr("\n");

	if ((size_requested * 100) + sizeof(t_block_mem) <= TINY * (size_t)getpagesize())
		return 0;
	if ((size_requested * 100) + sizeof(t_block_mem) <= SMALL * (size_t)getpagesize())
		return 1;
	return 2;
}



void			set_metadata(t_block_mem *mem, size_t size_requested, t_block_mem *next_block) {
	mem->size = size_requested;
	mem->used = 1;
	mem->next = next_block;

	// ft_putstr("SET METADATA : 0x");
	// print_addr((void *)mem);
	// ft_putstr(" ---> ");
	// printsize(mem->size);
	// ft_putstr("\n");
}

void			set_metadata_next_block(t_block_mem *mem, t_block_mem *next_block) {
	mem->next = next_block;
}


void			*request_memory(size_t size_requested, int8_t zone) {
	size_t		size_malloc;

	if (zone == 0)
		size_malloc = getpagesize() * TINY;
	else if (zone == 1)
		size_malloc = getpagesize() * SMALL;
	else
		size_malloc = size_requested + sizeof(t_block_mem);
	return mmap(0, size_malloc, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

void			*create_new_page(size_t size_requested, int8_t zone)
{
	void		*new_page;

	new_page = request_memory(size_requested, zone);
	if (new_page == (void *) -1)
		return NULL;
	set_metadata((t_block_mem*)new_page, size_requested, NULL);
	return (new_page);
}

void			*find_next_mem_large(t_block_mem **mem) {
	while (*mem != NULL)
	{
		mem = &(*mem)->next;
	}
	ft_putstr("Last addr in large :");
	print_addr(*mem);
	ft_putstr("\n");
	return ((void *)(*mem));
}

void			*find_next_mem_tn_sm(t_block_mem **mem, size_t size_requested, int8_t zone) {
	t_block_mem		**before;
	size_t			size_page;
	size_t			size_used_total;

	if (zone == 0)
		size_page = getpagesize() * TINY;
	else
		size_page = getpagesize() * SMALL;
	before = mem;
	size_used_total = (*mem)->size + sizeof(t_block_mem);
	mem = &(*mem)->next;
	while (*mem != NULL)
	{
		if (size_used_total + size_requested + sizeof(t_block_mem) > size_page)
			size_used_total = (*mem)->size + sizeof(t_block_mem);
		if ((*mem)->used == 0) {
			// when somewhere have enough space to rewrite
			if (size_requested + sizeof(t_block_mem) + size_used_total <= size_page)
			{
				ft_putstr("Space free enough big to reuse (after use of free)\n");
				set_metadata((*mem), size_requested, (*mem)->next);
				return (void *)(*mem) + sizeof(t_block_mem);
			}
		}
		size_used_total = size_used_total + (*mem)->size + sizeof(t_block_mem);
		before = mem;
		mem = &(*mem)->next;
	}
	if (size_used_total + size_requested + sizeof(t_block_mem) > size_page)
	{
		ft_putstr("Creation of new page and return ptr on free space\n");
		// print_debug(size_used_total, "size_used_total");
		// create new page

		void *ptr = create_new_page(size_requested, zone);
		set_metadata_next_block((void *)(*before), (t_block_mem *)ptr);
		return (ptr);

		return (create_new_page(size_requested, zone));
	}
	print_debug(size_used_total + sizeof(t_block_mem) + size_requested, "size_used_total");
	set_metadata((void *)(*before) + (sizeof(t_block_mem) + (*before)->size + 1), size_requested, NULL);
	set_metadata_next_block((void *)(*before), (void *)(*before) + (sizeof(t_block_mem) + (*before)->size + 1));
	return ((void *)(*before) + (sizeof(t_block_mem) + (*before)->size + 1));
}

void	print_debug(size_t debug, char *name) {
	ft_putstr("Debug: ");
	ft_putstr(name);
	ft_putstr(" = ");
	printsize(debug);
	ft_putstr("\n");
}

void			*malloc(size_t size) {
	void			*alloc_requested;
	t_block_mem		**mem;
	int8_t			zone;

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
			alloc_requested = find_next_mem_tn_sm(mem, size, zone);
		else
			alloc_requested = find_next_mem_large(mem);
	}
	if (alloc_requested == NULL)
		return NULL;
	return alloc_requested + sizeof(t_block_mem);
}
