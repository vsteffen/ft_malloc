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

void		print_debug_calloc(size_t size, size_t count, void *new_alloc)
{
	if (g_env == 1)
	{
		ft_putstr("FT_MALLOC: calloc: count -> [");
		print_size(count);
		ft_putstr("] - size -> [");
		print_size(size);
		ft_putstr("] = new allocation -> [0x");
		print_addr(new_alloc);
		ft_putstr("]\n");
	}
}

void		print_debug_free(void *ptr)
{
	if (g_env == 1)
	{
		ft_putstr("FT_MALLOC: free: ptr -> [0x");
		print_addr(ptr);
		ft_putstr("]\n");
	}
}

void		print_debug_malloc(size_t size , void *new_alloc)
{
	if (g_env == 1)
	{
		ft_putstr("FT_MALLOC: malloc: size -> [");
		print_size(size);
		ft_putstr("] = new allocation -> [0x");
		print_addr(new_alloc);
		ft_putstr("]\n");
	}
}

void		print_debug_realloc(void *ptr, size_t size, void *new_alloc)
{
	if (g_env == 1)
	{
		ft_putstr("FT_MALLOC: realloc: ptr -> [0x");
		print_addr(ptr);
		ft_putstr("] - size -> [");
		print_size(size);
		ft_putstr("] = new allocation -> [0x");
		print_addr(new_alloc);
		ft_putstr("]\n");
	}
}

void		print_debug_reallocf(void *ptr, size_t size, void *new_alloc)
{
	if (g_env == 1)
	{
		ft_putstr("FT_MALLOC: reallocf: ptr -> [0x");
		print_addr(ptr);
		ft_putstr("] - size -> [");
		print_size(size);
		ft_putstr("] = new allocation -> [0x");
		print_addr(new_alloc);
		ft_putstr("]\n");
	}
}

// void	print_debug_size_t(size_t debug, char *name)
// {
// 	if (g_env == 1)
// 	{
// 		ft_putstr("Debug: ");
// 		ft_putstr(name);
// 		ft_putstr(" = ");
// 		print_size(debug);
// 		ft_putstr("\n");
// 	}
// }
//
// void	print_debug_addr(void *debug, char *name)
// {
// 	if (g_env == 1)
// 	{
// 		ft_putstr("Debug: ");
// 		ft_putstr(name);
// 		ft_putstr(" = 0x");
// 		print_addr(debug);
// 		ft_putstr("\n");
// 	}
// }
//
// // void	print_debugf_size_t(size_t debug, char *name)
// // {
// // 	ft_putstr("Debug: ");
// // 	ft_putstr(name);
// // 	ft_putstr(" = ");
// // 	print_size(debug);
// // 	ft_putstr("\n");
// // }
// //
// // void	print_debugf_addr(void *debug, char *name)
// // {
// // 	ft_putstr("Debug: ");
// // 	ft_putstr(name);
// // 	ft_putstr(" = 0x");
// // 	print_addr(debug);
// // 	ft_putstr("\n");
// // }
