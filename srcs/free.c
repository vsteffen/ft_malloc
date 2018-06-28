#include "ft_malloc.h"

void	free(void *ptr) {
	write(1, "ft_free called!\n", 16);

	if (!ptr)
		return ;
	if (munmap(ptr, 0) == 0)
		write(1, "ft_free succeeded!\n", 19);
	else
		write(1, "ft_free failed!\n", 16);
}
