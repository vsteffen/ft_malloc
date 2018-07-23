/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:11:10 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/23 17:11:15 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*memory_management_mutex_3(void)
{
	print_mem(g_mem[0], "TINY");
	print_mem(g_mem[1], "SMALL");
	print_mem(g_mem[2], "LARGE");
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}

void	*memory_management_mutex_2(void *ptr, size_t size, int8_t action)
{
	if (action == 2) // malloc
	{
		ptr = start_malloc(size);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	else if (action == 3) // realloc
	{
		ptr = start_realloc(ptr, size);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	else if (action == 4)
	{
		ptr = start_realloc(ptr, size); // reallocf
		if (ptr == NULL)
			start_free(ptr);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	return (memory_management_mutex_3());
}

void	*memory_management_mutex(void *ptr, size_t size, size_t count, \
	int8_t action)
{
	t_block_mem		*new_mem;

	pthread_mutex_lock(&g_mutex);
	if (action == 0) // calloc
	{
		ptr = start_malloc(count * size);
		if (!ptr)
			return (NULL);
		new_mem = (t_block_mem*)(ptr - sizeof(t_block_mem));
		ft_bzero(ptr, new_mem->size);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	else if (action == 1) // free
	{
		start_free(ptr);
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	return (memory_management_mutex_2(ptr, size, action));
}
