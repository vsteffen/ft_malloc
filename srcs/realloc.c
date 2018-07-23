#include "ft_malloc.h"

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
				return (1);
			mem = mem->next;
		}
		i++;
	}
	return (0);
}

void	*copy_in_new_malloc_and_free(void *old_block, size_t size)
{
	void		*new_alloc;
	t_block_mem	*old_mem;

	new_alloc = start_malloc(size);
	if (new_alloc == NULL)
		return (NULL);
	old_mem = (t_block_mem *)(old_block - sizeof(t_block_mem));
	ft_memcpy(new_alloc, old_block, old_mem->size);
	start_free(old_block);
	return (new_alloc);
}

void	*start_realloc(void *ptr, size_t size)
{
	t_block_mem		*mem;

	print_debug_addr(ptr, "Realloc address");
	print_debug_size_t(size, "Realloc size");
	if (!ptr)
	{
		return (start_malloc(size));
	}
	if (isset_addr(ptr) == 0)
	{
		return (NULL);
	}
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	if (size % (sizeof(uintptr_t) * 2) > 0)
		size = (size / (sizeof(uintptr_t) * 2) + 1) * (sizeof(uintptr_t) * 2);
	if (mem->size >= size)
	{
		return (ptr);
		// if (mem->size <= size + sizeof(t_block_mem))
		// {
		// 	pthread_mutex_unlock(&g_mutex);
		// 	return (ptr);
		// }
		// set_metadata((t_block_mem*)((void *)mem + sizeof(t_block_mem) + size), mem->size - (size + sizeof(t_block_mem)), mem->next);
		// set_metadata_next_block(mem, (t_block_mem*)(((void *)mem) + (sizeof(t_block_mem) + size)));
		// mem->size = size;
		// start_free((void *)mem + (sizeof(t_block_mem) * 2) + size);
		// pthread_mutex_unlock(&g_mutex);
		// return ((void*)mem->next + sizeof(t_block_mem));
	}

	// if (get_zone(mem->size) != get_zone(size) || get_zone(mem->size) == 2) // Can't do this because emacs sucks... a lot
	// 	return (copy_in_new_malloc_and_free(ptr, size));
	return (copy_in_new_malloc_and_free(ptr, size)); // to remove
}

void	*realloc(void *ptr, size_t size) {
	return (memory_management_mutex(ptr, size, 0, 3));
}

void	*reallocf(void *ptr, size_t size)
{
	return (memory_management_mutex(ptr, size, 0, 4));
}
