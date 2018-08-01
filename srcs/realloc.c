/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:41:05 by vsteffen          #+#    #+#             */
/*   Updated: 2018/08/01 23:41:06 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_block_mem		*isset_addr_and_get_previous(void *ptr)
{
	t_block_mem		*mem;
	t_block_mem		*before;
	int8_t			i;

	i = 0;
	while (i < 3)
	{
		mem = g_mem[i];
		before = mem;
		while (mem)
		{
			if (mem->used == 1 && (void*)mem + sizeof(t_block_mem) == ptr)
				return (before);
			before = mem;
			mem = mem->next;
		}
		i++;
	}
	return (NULL);
}

void			*copy_in_new_malloc_and_free(void *old_block, size_t size)
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

void			*start_realloc(void *ptr, size_t size)
{
	t_block_mem		*mem;

	if (!ptr)
		return (start_malloc(size));
	if (isset_addr_and_get_previous(ptr) == NULL)
		return (NULL);
	mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
	if (size % (sizeof(uintptr_t) * 2) > 0)
		size = (size / (sizeof(uintptr_t) * 2) + 1) * (sizeof(uintptr_t) * 2);
	if (mem->size >= size)
	{
		if (mem->size <= size + sizeof(t_block_mem))
		{
			return (ptr);
		}
		set_metadata((t_block_mem*)(ptr + size), mem->size - \
			(size + sizeof(t_block_mem)), mem->next);
		set_metadata_next_block(mem, (t_block_mem*)(ptr + size));
		mem->size = size;
		start_free(ptr + size + sizeof(t_block_mem));
		return (ptr);
	}
	return (copy_in_new_malloc_and_free(ptr, size));
}

void			*realloc(void *ptr, size_t size)
{
	void	*new_alloc;

	new_alloc = memory_management_mutex(ptr, size, 0, 3);
	print_debug_realloc(ptr, size, new_alloc);
	return (new_alloc);
}

void			*reallocf(void *ptr, size_t size)
{
	void	*new_alloc;

	new_alloc = memory_management_mutex(ptr, size, 0, 4);
	print_debug_reallocf(ptr, size, new_alloc);
	return (new_alloc);
}
