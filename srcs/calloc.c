#include "ft_malloc.h"

void	*calloc(size_t count, size_t size)
{
	return (memory_management_mutex(NULL, size, count, 0));
}
