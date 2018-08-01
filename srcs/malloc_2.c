/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:37:11 by vsteffen          #+#    #+#             */
/*   Updated: 2018/08/01 23:37:12 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*filled_zone(size_t size_requested, t_block_mem *before, \
	int8_t zone)
{
	void			*next_alloc;

	next_alloc = create_new_page(size_requested, zone);
	set_metadata_next_block(before, (t_block_mem *)next_alloc);
	return (next_alloc);
}

void		*unfilled_zone(size_t size_requested, t_block_mem *before)
{
	void			*next_alloc;

	next_alloc = (void *)before + sizeof(t_block_mem) + before->size;
	set_metadata((t_block_mem*)next_alloc, size_requested, NULL);
	set_metadata_next_block(before, (t_block_mem*)next_alloc);
	return (next_alloc);
}
