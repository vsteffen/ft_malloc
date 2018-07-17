#include "ft_malloc.h"

// NOT WORKING


void	*valloc(size_t size)
{
	void		*ptr;

	write(1, "VALLOC CALLED\n", 14);
	pthread_mutex_lock(&g_mutex);
	print_debug_size_t(size, "Valloc size");
	ptr = start_malloc(size);
	memset(ptr, 0, size);
	pthread_mutex_unlock(&g_mutex);
	return ptr;
}


void	*reallocf(void *ptr, size_t size)
{
	write(1, "REALLOCF CALLED\n", 16);
	pthread_mutex_lock(&g_mutex);
 	print_debug_addr(ptr, "Reallocf addr");
	print_debug_size_t(size, "Reallocf size");
	ptr = start_malloc(size);
	memset(ptr, 0, size);
	pthread_mutex_unlock(&g_mutex);
	return ptr;
}
