#include "ft_malloc.h"

void	*calloc(size_t count, size_t size)
{
	void	*new_alloc;

	new_alloc = memory_management_mutex(NULL, size, count, 0);
	print_debug_calloc(count, size, new_alloc);
	return (new_alloc);
}
