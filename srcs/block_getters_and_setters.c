/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_getters_and_setters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:42:29 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/23 23:42:31 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		get_size_page(size_t size_requested, int8_t zone)
{
	size_t		size_zone;

	if (zone == 0)
		size_zone = TINY;
	else if (zone == 1)
		size_zone = SMALL;
	else
		size_zone = size_requested;
	if (size_zone % (sizeof(uintptr_t) * 2) > 0)
		size_zone = (size_zone / (sizeof(uintptr_t) * 2) + 1) * \
			(sizeof(uintptr_t) * 2);
	if (zone < 2)
	{
		return (((size_zone * 100 + sizeof(t_block_mem) * 100) / \
			getpagesize() + 1) * getpagesize());
	}
	return (((size_zone + sizeof(t_block_mem)) / getpagesize() + 1) * \
		getpagesize());
}

int8_t		get_zone(size_t size_requested)
{
	if (size_requested <= TINY)
		return (0);
	if (size_requested <= SMALL)
		return (1);
	return (2);
}

void		set_metadata(t_block_mem *mem, size_t size_requested, \
	t_block_mem *next_block)
{
	mem->size = size_requested;
	mem->used = 1;
	mem->new_page = 0;
	mem->next = next_block;
}

void		set_metadata_next_block(t_block_mem *mem, t_block_mem *next_block)
{
	mem->next = next_block;
}
