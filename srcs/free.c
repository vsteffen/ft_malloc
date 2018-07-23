#include "ft_malloc.h"

void	start_free(void *ptr)
{
	t_block_mem		*mem;
	t_block_mem		*tmp_block;
	t_block_mem		**beg_global;
	int8_t			zone;

	// print_debugf_addr(ptr, "Free address");
	if (!ptr || (tmp_block = isset_addr_and_get_previous(ptr)) == NULL)
		return ;
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	if (mem->size % (sizeof(uintptr_t) * 2) > 0)
		zone = get_zone((mem->size / (sizeof(uintptr_t) * 2) + 1) * (sizeof(uintptr_t) * 2));
	zone = get_zone((mem->size));
	if (zone < 2)
	{
		mem->used = 0;
		if (&tmp_block != &mem)
		{
			if (tmp_block->used == 0 && mem->new_page == 0)
			{
				tmp_block->next = mem->next;
				tmp_block->size += mem->size + sizeof(t_block_mem);
			}
			tmp_block = mem->next;
			if (tmp_block)
			{
				if (tmp_block->used == 0 && tmp_block->new_page == 0)
				{
					mem->next = tmp_block->next;
					mem->size += tmp_block->size + sizeof(t_block_mem);
				}
			}
		}
	}
	else
	{
		if (&tmp_block != &mem)
			tmp_block->next = mem->next;
		else if (&mem == &(g_mem[2]))
		{
			beg_global = &g_mem[2];
			*beg_global = mem->next;
		}
		if (munmap(ptr - sizeof(t_block_mem), 0) == 0)
			(void)ptr; // success
		else
			(void)ptr; // failed
	}
}

void	free(void *ptr) {
	memory_management_mutex(ptr, 0, 0, 1);
}
