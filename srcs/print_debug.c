/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:41:21 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/23 23:41:22 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	print_debug_size_t(size_t debug, char *name)
{
	if (DEBUG == 1)
	{
		ft_putstr("Debug: ");
		ft_putstr(name);
		ft_putstr(" = ");
		print_size(debug);
		ft_putstr("\n");
	}
}

void	print_debug_addr(void *debug, char *name)
{
	if (DEBUG == 1)
	{
		ft_putstr("Debug: ");
		ft_putstr(name);
		ft_putstr(" = 0x");
		print_addr(debug);
		ft_putstr("\n");
	}
}

void	print_debugf_size_t(size_t debug, char *name)
{
	ft_putstr("Debug: ");
	ft_putstr(name);
	ft_putstr(" = ");
	print_size(debug);
	ft_putstr("\n");
}

void	print_debugf_addr(void *debug, char *name)
{
	ft_putstr("Debug: ");
	ft_putstr(name);
	ft_putstr(" = 0x");
	print_addr(debug);
	ft_putstr("\n");
}
