#include "ft_malloc.h"

void	*mutex_unlock_with_ptr(void *ptr) {
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}

int8_t	isset_addr(void *ptr) {
	t_block_mem		*mem;
	int8_t			i;

	i = 0;
	while (i < 3)
	{
		mem = g_mem[i];
		while (mem)
		{
			if (mem->used == 1 && (void*)mem + sizeof(t_block_mem) == ptr)
			{
				// ft_putstr("Address is valid\n");
				return (1);
			}
			mem = mem->next;
		}
		i++;
	}
	// ft_putstr("Address receive isn't valid!\n");
	return (0);
}

size_t	get_size_left_on_page(t_block_mem *mem) {
	size_t	total_size;

	while (mem && mem->new_page == 0)
		mem = mem->prev;
	total_size = 0;
	while (mem && mem->new_page == 0)
	{
		total_size += sizeof(t_block_mem) + mem->size;
		mem = mem->next;
	}
	if (get_zone(mem->size) == 0)
		return ((getpagesize() * TINY) - total_size);
	return ((getpagesize() * SMALL) - total_size);
}

void	*copy_in_new_malloc_and_free(t_block_mem *mem, void *ptr, size_t size)
{
	t_block_mem		*new_alloc;

	new_alloc = (t_block_mem*)start_malloc(size);
	// ft_memcpy(new_alloc, (void*)mem, mem->size);
	ft_memcpy(new_alloc, (void*)mem + sizeof(t_block_mem), mem->size);
	start_free(ptr);
	return ((void*)new_alloc);
}

void	*realloc(void *ptr, size_t size) {
	t_block_mem		*mem;

	write(1, "REALLOC CALLED\n", 15);
	pthread_mutex_lock(&g_mutex);
	print_debug_addr(ptr, "Realloc address");
	print_debug_size_t(size, "Realloc size");
	if (!ptr)
		return (mutex_unlock_with_ptr(start_malloc(size)));
	if (isset_addr(ptr) == 0)
		return (mutex_unlock_with_ptr(NULL));
	if (size == 0)
	{
		start_free(ptr);
		return (mutex_unlock_with_ptr(start_malloc(0)));
	}
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	// don't forget realloc in new zone
	if (get_zone(mem->size) != get_zone(size) || get_zone(mem->size) == 2)
		return (mutex_unlock_with_ptr(copy_in_new_malloc_and_free(mem, ptr, size)));
	if (mem->size >= size)
	{
		if (mem->size <= size + sizeof(t_block_mem))
		{
			return (mutex_unlock_with_ptr(copy_in_new_malloc_and_free(mem, ptr, size)));
		}
		set_metadata((t_block_mem*)(((void *)mem) + sizeof(t_block_mem) + size), mem->size - (size + sizeof(t_block_mem)), mem, mem->next);
		set_metadata_next_block(mem, (t_block_mem*)(((void *)mem) + (sizeof(t_block_mem) + size)));
		mem->size = size;
		start_free((void *)mem + (sizeof(t_block_mem) * 2) + size);
		return (mutex_unlock_with_ptr((void*)mem->next + sizeof(t_block_mem)));
	}
	if (mem->next == NULL && size <= get_size_left_on_page(mem))
	{
		mem->size = size;
		return (mutex_unlock_with_ptr(ptr));
	}
	return (mutex_unlock_with_ptr(copy_in_new_malloc_and_free(mem, ptr, size)));
}
