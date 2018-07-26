#include "ft_malloc.h"

void	*calloc(size_t count, size_t size)
{
	add_alloc_history(0, NULL, count * size);
	return (memory_management_mutex(NULL, size, count, 0));
}
