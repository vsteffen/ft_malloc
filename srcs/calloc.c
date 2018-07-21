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
	void		*ptr;

	// write(1, "CALLOC CALLED\n", 14);
	// print_debug_size_t(count, "Calloc count");
	// print_debug_size_t(size, "Calloc size");
	ptr = start_malloc(count * size);
	memset(ptr, 0, count * size + size % (sizeof(uintptr_t) * 2));
	// ft_bzero(ptr, count * size + size % (sizeof(uintptr_t) * 2));
	return ptr;
}
