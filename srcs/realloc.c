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
	// size_t	total_size;


	// to do without prev
	(void)mem;
	return 0;



	// while (mem && mem->new_page == 0)
	// 	mem = mem->prev;
	// total_size = 0;
	// while (mem && mem->new_page == 0)
	// {
	// 	total_size += sizeof(t_block_mem) + mem->size;
	// 	mem = mem->next;
	// }
	// if (get_zone(mem->size) == 0)
	// 	return ((getpagesize() * TINY) - total_size);
	// return ((getpagesize() * SMALL) - total_size);
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
		return (start_malloc(size));
	print_debug_size_t(size, "Realloc true size");
	if (isset_addr(ptr) == 0)
		return (NULL);


	return (copy_in_new_malloc_and_free(ptr, size));


	if (size == 0)
	{
		start_free(ptr);
		return (start_malloc(size));
	}
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	// don't forget realloc in new zone
	if (get_zone(mem->size) != get_zone(size) || get_zone(mem->size) == 2)
		return (copy_in_new_malloc_and_free(ptr, size));
	if (mem->size >= size)
	{
		if (mem->size <= size + sizeof(t_block_mem))
		{
			return (copy_in_new_malloc_and_free(ptr, size));
		}
		set_metadata((t_block_mem*)((void *)mem + sizeof(t_block_mem) + size), mem->size - (size + sizeof(t_block_mem)), mem->next);
		set_metadata_next_block(mem, (t_block_mem*)(((void *)mem) + (sizeof(t_block_mem) + size)));
		mem->size = size;
		start_free((void *)mem + (sizeof(t_block_mem) * 2) + size);
		return ((void*)mem->next + sizeof(t_block_mem));
	}
	return (copy_in_new_malloc_and_free(ptr, size)); // to remove


	if (mem->next == NULL && size <= get_size_left_on_page(mem))
	{
		mem->size = size;
		return (ptr);
	}
	return (copy_in_new_malloc_and_free(ptr, size));
}

void	*realloc(void *ptr, size_t size) {
	void	*realloc;

	// write(1, "REALLOC CALLED\n", 15);
	// pthread_mutex_lock(&g_mutex);
	realloc = start_realloc(ptr, size);
	// write(1, "REALLOC END\n", 12);
	print_debug_addr(realloc, "Realloc ptr return");
	// pthread_mutex_unlock(&g_mutex);
	return (realloc);
}

void	*reallocf(void *ptr, size_t size)
{
	void	*reallocf;

	// pthread_mutex_lock(&g_mutex);
	// write(1, "REALLOCF CALLED\n", 16);
	reallocf = start_realloc(ptr, size);
	if (reallocf == NULL)
		free(ptr);
	print_debug_addr(realloc, "Reallocf ptr return");
	// write(1, "REALLOCF END\n", 13);
	// pthread_mutex_unlock(&g_mutex);
	return (reallocf);
}
