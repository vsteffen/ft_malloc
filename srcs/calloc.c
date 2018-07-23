#include "ft_malloc.h"

void	print_debugf_size_t(size_t debug, char *name) {
		ft_putstr("Debug: ");
		ft_putstr(name);
		ft_putstr(" = ");
		print_size(debug);
		ft_putstr("\n");
}

void	print_debugf_addr(void *debug, char *name) {
		ft_putstr("Debug: ");
		ft_putstr(name);
		ft_putstr(" = 0x");
		print_addr(debug);
		ft_putstr("\n");
}

void	*calloc(size_t count, size_t size)
{
	return (memory_management_mutex(NULL, size, count, 0));
}
