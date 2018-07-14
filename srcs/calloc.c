#include "ft_malloc.h"

void	*calloc(size_t count, size_t size)
{
	void		*ptr;

	print_debug_size_t(count, "Calloc count");
	print_debug_size_t(size, "Calloc size");
	ptr = malloc(count * size);
	memset(ptr, 0, count * size);
	return ptr;
}
