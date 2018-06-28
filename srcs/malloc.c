#include "ft_malloc.h"

int8_t			get_zone(size_t size_requested) {
	if (size_requested * 100 <= TINY)
		return 1;
	if (size_requested * 100 <= SMALL)
		return 2;
	return 3;
}


void			set_metadata(void *new_alloc, size_t size_requested) {
	t_block_mem		*mem;

	mem = (t_block_mem *)new_alloc;
	mem->size = size_requested;
	mem->size_used = size_requested;
	mem->used = 1;
	mem->next = NULL;
}

void			*request_memory(size_t size_requested) {
	size_t		size_malloc;

	size_malloc = getpagesize() * (((size_requested * 100 + sizeof(t_block_mem)) / getpagesize()) + 1);
	return mmap(0, size_malloc, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

void			print_debug() {
	t_block_mem		*mem;

	mem = g_mem[0];
	ft_putstr("\n ---> ");
	printsize(mem->size);
	ft_putstr("\n");
}

void			*malloc(size_t size) {
	void			*new_alloc;

	// write(1, "ft_malloc called!\n", 18);
	new_alloc = request_memory(size);
	if (new_alloc == (void *) -1)
		return NULL;
	if (g_mem[0] == NULL)
	{
		set_metadata(new_alloc, size);
		g_mem[0] = (t_block_mem*)new_alloc;
	}
	// print_debug();
	show_alloc_mem();
	return new_alloc + sizeof(t_block_mem);
}
