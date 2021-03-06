/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:40:01 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/23 23:40:03 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*request_memory(size_t size_requested, int8_t zone)
{
	size_t		size_malloc;

	size_malloc = get_size_page(size_requested, zone);
	return (mmap(0, size_malloc, \
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
}

void	*create_new_page(size_t size_requested, int8_t zone)
{
	void		*new_page;
	t_block_mem	*mem;

	new_page = request_memory(size_requested, zone);
	if (new_page == MAP_FAILED)
		return (NULL);
	set_metadata((t_block_mem*)new_page, size_requested, NULL);
	mem = (t_block_mem*)new_page;
	mem->new_page = 1;
	return (new_page);
}

void	*memory_management_mutex_3(void *ptr, int8_t action)
{
	size_t		total;

	if (action == 5)
	{
		total = 0;
		print_zone(g_mem[0], "TINY", &total);
		print_zone(g_mem[1], "SMALL", &total);
		print_zone(g_mem[2], "LARGE", &total);
		ft_putstr("Total : ");
		print_size(total);
		ft_putstr(" octets\n");
	}
	else if (action == 6)
		show_alloc_mem_dump(ptr);
	else
		print_history();
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}

void	*memory_management_mutex_2(void *ptr, size_t size, int8_t action)
{
	if (action == 2)
	{
		add_alloc_history(2, NULL, size);
		ptr = start_malloc(size);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	else if (action == 3)
	{
		add_alloc_history(3, ptr, size);
		ptr = start_realloc(ptr, size);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	else if (action == 4)
	{
		add_alloc_history(4, ptr, size);
		ptr = start_realloc(ptr, size);
		if (ptr == NULL)
			start_free(ptr);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	return (memory_management_mutex_3(ptr, action));
}

void	*memory_management_mutex(void *ptr, size_t size, size_t count, \
	int8_t action)
{
	t_block_mem		*new_mem;

	pthread_mutex_lock(&g_mutex);
	set_env_var();
	if (action == 0)
	{
		add_alloc_history(0, NULL, count * size);
		ptr = start_malloc(count * size);
		if (!ptr)
			return (NULL);
		new_mem = (t_block_mem*)(ptr - sizeof(t_block_mem));
		ft_bzero(ptr, new_mem->size);
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	else if (action == 1)
	{
		add_alloc_history(1, ptr, 0);
		start_free(ptr);
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	return (memory_management_mutex_2(ptr, size, action));
}
