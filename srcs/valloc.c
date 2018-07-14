#include "ft_malloc.h"

// NOT WORKING


void	*valloc(size_t size)
{
	void		*ptr;

	print_debug_size_t(size, "Valloc size");
	ptr = malloc(size);
	memset(ptr, 0, size);
	return ptr;
}


void	*reallocf(void *ptr, size_t size)
{
 	print_debug_addr(ptr, "Reallocf addr");
	print_debug_size_t(size, "Reallocf size");
	ptr = malloc(size);
	memset(ptr, 0, size);
	return ptr;
}
