#include "ft_malloc.h"

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
		if (mem->used == 0)
		{
			if (mem->size >= size_requested)
			{
				mem->used = 1;
				if (mem->size >= size_requested + sizeof(t_block_mem)) // if we have space enough to create free page after the part reuse of this one
				{
					new_space_free = (t_block_mem*)((void *)mem + sizeof(t_block_mem) + size_requested);
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
		next_alloc = create_new_page(size_requested, zone);
		set_metadata_next_block(before, (t_block_mem *)next_alloc);
		return (next_alloc);
	}
	next_alloc = (void *)before + sizeof(t_block_mem) + before->size;
	set_metadata((t_block_mem*)next_alloc, size_requested, NULL);
	set_metadata_next_block(before, (t_block_mem*)next_alloc);
	return (next_alloc);
}

void			*start_malloc(size_t size)
{
	void			*alloc_requested;
	t_block_mem		**mem;
	int8_t			zone;

	if (size % (sizeof(uintptr_t) * 2) > 0)
		size = (size / (sizeof(uintptr_t) * 2) + 1) * (sizeof(uintptr_t) * 2);
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
	if (alloc_requested == NULL)
		return (NULL);
	return (alloc_requested + sizeof(t_block_mem));
}

void			*malloc(size_t size) {
	return (memory_management_mutex(NULL, size, 0, 2));
}
