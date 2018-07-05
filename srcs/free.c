#include "ft_malloc.h"

void	free(void *ptr) {
	t_block_mem		*mem;

	if (!ptr)
		return ;
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	if (get_zone(mem->size) < 2)
	{
		mem->used = 0;
		write(1, "ft_free succeeded!\n", 19);
	}
	// if (munmap(ptr, 0) == 0)
	// 	write(1, "ft_free succeeded!\n", 19);
	// else
	// 	write(1, "ft_free failed!\n", 16);
}
