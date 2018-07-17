#include "ft_malloc.h"

void	*calloc(size_t count, size_t size)
{
	void		*ptr;

	write(1, "CALLOC CALLED\n", 14);
	pthread_mutex_lock(&g_mutex);
	print_debug_size_t(count, "Calloc count");
	print_debug_size_t(size, "Calloc size");
	ptr = start_malloc(count * size);
	memset(ptr, 0, count * size);
	pthread_mutex_unlock(&g_mutex);
	return ptr;
}
