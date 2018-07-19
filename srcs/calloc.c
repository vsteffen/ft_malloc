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

	pthread_mutex_lock(&g_mutex);
	// write(1, "CALLOC CALLED\n", 14);
	print_debug_size_t(count, "Calloc count");
	print_debug_size_t(size, "Calloc size");
	ptr = start_malloc(count * size);
	// size = (size / (sizeof(uintptr_t) * 2) + 2) * (sizeof(uintptr_t) * 2);
	memset(ptr, 0, count * size);
	// write(1, "CALLOC END\n", 11);
	memset(ptr, 0, count * size);
	// print_debugf_size_t(size, "Calloc size");
	// print_debugf_addr(ptr, "Calloc return ptr");
	// if (size == 192)
	// {
	// 	t_block_mem *mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	// 	print_debugf_size_t(mem->size, "mem->size");
	// 	print_debugf_size_t(mem->used, "mem->used");
	// 	print_debugf_size_t(mem->new_page, "mem->new_page");
	// 	print_debugf_addr(mem->next, "mem->next");
	// 	char *str = (char*)ptr;
	// 	char *str2 = (char*)(ptr - 32 - 4);
	// 	for(int i = 0; i < 192; i++)
	// 	{
	// 		print_debugf_size_t(str[i], "content");
	// 	}
	// 	ft_putstr("\n");
	// 	for(int i = 0; i < 4; i++)
	// 	{
	// 		print_debugf_size_t(str2[i], "content");
	// 	}
	// }
	pthread_mutex_unlock(&g_mutex);
	return ptr;
}
