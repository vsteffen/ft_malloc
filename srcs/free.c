#include "ft_malloc.h"

void	start_free(void *ptr)
{
	t_block_mem		*mem;
	// t_block_mem		*tmp;
	int8_t			zone;

	// print_debugf_addr(ptr, "Free address");
	pthread_mutex_lock(&g_mutex);
	if (!ptr || isset_addr(ptr) == 0)
	{
		// print_debugf_addr(ptr, "PTR FALSE");
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));

	if (mem->size % (sizeof(uintptr_t) * 2) > 0)
		zone = get_zone((mem->size / (sizeof(uintptr_t) * 2) + 1) * (sizeof(uintptr_t) * 2));
	zone = get_zone((mem->size));
	// tmp = mem->prev;
	// if (tmp)
	// {
	// 	if (zone < 2)
	// 	{
	// 		if (tmp->used == 0 && mem->new_page == 0)
	// 		{
	// 			tmp->next = mem->next;
	// 			tmp->size += mem->size + sizeof(t_block_mem);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		tmp->next = mem->next;
	// 	}
	// }
	// tmp = mem->next;
	// if (tmp)
	// {
	// 	if (zone < 2)
	// 	{
	// 		if (tmp->used == 0 && tmp->new_page == 0)
	// 		{
	// 			mem->next = tmp->next;
	// 			mem->size += tmp->size + sizeof(t_block_mem);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (&mem == &(g_mem[2]))
	// 			g_mem[2] = tmp;
	// 		tmp->prev = mem->prev;
	// 	}
	// }
	if (zone < 2)
	{
		mem->used = 0;
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	if (munmap(ptr - sizeof(t_block_mem), 0) == 0)
		(void)ptr; // success
	else
		(void)ptr; // failed
	pthread_mutex_unlock(&g_mutex);
}

void	free(void *ptr) {
	// ft_putstr("FREE CALLED\n");
	start_free(ptr);
	// ft_putstr("FREE END\n");
}
