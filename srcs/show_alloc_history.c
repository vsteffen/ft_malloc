/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 00:00:44 by vsteffen          #+#    #+#             */
/*   Updated: 2018/08/02 00:00:45 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		set_metadata_hist_mem(t_histo_mem *history, int8_t action, \
	void *ptr, size_t size)
{
	history->action = action;
	history->ptr = ptr;
	history->size = size;
	history->next = NULL;
}

void		add_alloc_history(int8_t action, void *ptr, size_t size)
{
	t_histo_mem		*history;

	if ((g_env & (1 << 1)) == (1 << 1))
	{
		history = (t_histo_mem*)mmap(0, get_size_page(sizeof(t_histo_mem), 2), \
				PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		if ((void*)history == MAP_FAILED)
			return ;
		set_metadata_hist_mem(history, action, ptr, size);
		if (!g_history)
		{
			g_history = (t_histo_global*)mmap(0, get_size_page(\
				sizeof(t_histo_global), 2), \
				PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
			if ((void*)g_history == MAP_FAILED)
				return ;
			g_history->start = history;
			g_history->end = history;
		}
		else
		{
			g_history->end->next = history;
			g_history->end = history;
		}
	}
}

void		print_history_norme(int8_t action, t_histo_mem *history)
{
	if (action == 1)
	{
		ft_putstr(": free: ptr -> [0x");
		print_addr(history->ptr);
	}
	else if (action == 2)
	{
		ft_putstr(": malloc: size -> [");
		print_size(history->size);
	}
	else if (action == 3)
	{
		ft_putstr(": realloc: ptr -> [0x");
		print_addr(history->ptr);
		ft_putstr("] - size -> [");
		print_size(history->size);
	}
	else
	{
		ft_putstr(": reallocf: ptr -> [0x");
		print_addr(history->ptr);
		ft_putstr("] - size -> [");
		print_size(history->size);
	}
}

void		print_history(void)
{
	t_histo_mem		*history;
	size_t			id;
	int8_t			action;

	if (!g_history)
		return ;
	history = g_history->start;
	id = 1;
	while (history)
	{
		action = history->action;
		ft_putnbr(id);
		if (action == 0)
		{
			ft_putstr(": calloc: size -> [");
			print_size(history->size);
		}
		else
			print_history_norme(action, history);
		ft_putstr("]\n");
		history = history->next;
		id++;
	}
}

void		show_alloc_history(void)
{
	memory_management_mutex(NULL, 0, 0, 7);
}
