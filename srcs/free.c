#include "ft_malloc.h"

void	remove_empty_page(t_block_mem *page, t_block_mem **global_ptr, void *ptr)
{
	t_block_mem		*page_iter;
	t_block_mem		*page_tmp;
	t_block_mem		*prev_page_end;
	int8_t			used;

	prev_page_end = NULL;
	while (page)
	{
		prev_page_end = page->prev;
		used = 0;
		page_iter = page;
		page_tmp = page;
		while (page_iter && page_iter->new_page == 0)
		{
			if (used == 0)
				used = page_iter->used;
			page_iter = page_iter->next;
		}
		if (used == 0)
		{
			if (prev_page_end)
				prev_page_end->next = page_iter;
			if (page_iter)
				page_iter->prev = prev_page_end;
			if (&page_tmp == global_ptr)
				*global_ptr = page_iter;
			if (munmap(ptr, 0) == 0)
				(void)ptr; // success
			else
				(void)ptr; // failed
		}
		page = page_iter;
	}
}

void	free(void *ptr) {
	t_block_mem		*mem;
	t_block_mem		*tmp;
	uint8_t			count = 0;
	int8_t			zone;

	print_debug_addr(ptr, "Free address");
	if (!ptr || isset_addr(ptr) == 0)
		return ;
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	zone = get_zone(mem->size);
	tmp = mem->prev;
	if (tmp)
	{
		print_debug_size_t((size_t)zone, "zone");
		if (zone < 2)
		{
			if (tmp->used == 0 && mem->new_page == 0)
			{
				tmp->next = mem->next;
				tmp->size += mem->size + sizeof(t_block_mem);
			}
		}
		else
		{
			tmp->next = mem->next;
		}
	}
	tmp = mem->next;
	if (tmp)
	{
		if (zone < 2)
		{
			if (tmp->used == 0 && tmp->new_page == 0)
			{
				mem->next = tmp->next;
				mem->size += tmp->size + sizeof(t_block_mem);
			}
		}
		else
		{
			if (&mem == &g_mem[2])
				g_mem[2] = tmp;
			tmp->prev = mem->prev;
		}
	}
	if (zone < 2)
	{
		mem->used = 0;
		count++;
		if (count == 255)
			remove_empty_page((t_block_mem*)ptr, &g_mem[get_zone(mem->size)], ptr);
		return ;
	}
	if (munmap(ptr, 0) == 0)
		(void)ptr; // success
	else
		(void)ptr; // failed
}
