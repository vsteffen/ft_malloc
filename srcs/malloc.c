#include "ft_malloc.h"

void	*malloc(size_t size) {
	int				sizePage;
	void			*ptr;

	write(1, "ft_malloc called!\n", 18);
	sizePage = getpagesize() * (((size + sizeof(t_block_mem)) / getpagesize()) + 1);
	ptr = mmap(0, sizePage, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == (void *) -1)
		return NULL;
	return ptr;
}
