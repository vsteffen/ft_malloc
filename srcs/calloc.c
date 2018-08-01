/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:39:18 by vsteffen          #+#    #+#             */
/*   Updated: 2018/08/01 23:39:20 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*calloc(size_t count, size_t size)
{
	void	*new_alloc;

	new_alloc = memory_management_mutex(NULL, size, count, 0);
	print_debug_calloc(count, size, new_alloc);
	return (new_alloc);
}
