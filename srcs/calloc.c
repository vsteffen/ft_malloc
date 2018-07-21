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
	void			*ptr;
	t_block_mem		*new_mem;

	// write(1, "CALLOC CALLED\n", 14);
	ptr = start_malloc(count * size);
	if (!ptr)
		return (NULL);
	new_mem = (t_block_mem*)(ptr - sizeof(t_block_mem));
	ft_bzero(ptr, new_mem->size);
	return (ptr);
}
