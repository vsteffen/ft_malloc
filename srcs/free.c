#include "ft_malloc.h"

void	remove_empty_page(t_block_mem *page, t_block_mem **global_mem)
{
	t_block_mem		*mem;
	t_block_mem		*tmp;
	t_block_mem		*prev_page_end;
	int8_t			used;


	// verify gloabl adress and replace link between page removed
	prev_page_end = NULL;
	while (page)
	{
		prev_page_end = page->prev;
		used = 0;
		mem = page;
		while (mem && mem->new_page == 0)
		{
			if (used == 0)
				used = mem->used;
			mem = mem->next;
		}
		if (used == 0)
		{
			if (prev_page_end)
			{
				(void)tmp;
			}
			if (prev_page_end == NULL)
				*global_mem = mem->next;
		}
		page = mem;
	}
}

void	free(void *ptr) {
	t_block_mem		*mem;
	t_block_mem		*tmp;
	uint8_t			count = 0;

	if (!ptr)
		return ;
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	if (get_zone(mem->size) < 2)
	{
		mem->used = 0;
		tmp = mem->prev;
		if (tmp)
		{
			if (tmp->used == 0 && mem->new_page == 0)
			{
				tmp->next = mem->next;
				tmp->size += mem->size + sizeof(t_block_mem);
			}
		}
		tmp = mem->next;
		if (tmp)
		{
			if (tmp->used == 0 && tmp->new_page == 0)
			{
				mem->next = tmp->next;
				mem->size += tmp->size + sizeof(t_block_mem);
			}
		}
		count++;
		if (count == 255)
		{
			// check if a page is empty
			remove_empty_page((t_block_mem*)ptr, &g_mem[get_zone(mem->size)]);
		}
		write(1, "ft_free succeeded!\n", 19);
	}
	// if (munmap(ptr, 0) == 0)
	// 	write(1, "ft_free succeeded!\n", 19);
	// else
	// 	write(1, "ft_free failed!\n", 16);
}
