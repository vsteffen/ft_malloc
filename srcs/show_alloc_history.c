#include "ft_malloc.h"

void		add_alloc_history(int8_t action, void *ptr, size_t size)
{
	t_histo_mem		*history;

	history = (t_histo_mem*)mmap(0, get_size_page(sizeof(t_histo_mem), 2), \
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if ((void*)history == MAP_FAILED)
		return ;
	history->action = action;
	history->ptr = ptr;
	history->size = size;
	history->next = NULL;
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

void		print_history(void)
{
	t_histo_mem		*history;
	size_t			id;
	int8_t			action;

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
			ft_putstr("]\n");
		}
		else if (action == 1)
		{
			ft_putstr(": free: ptr -> [0x");
			print_addr(history->ptr);
			ft_putstr("]\n");
		}
		else if (action == 2)
		{
			ft_putstr(": malloc: size -> [");
			print_size(history->size);
			ft_putstr("]\n");
		}
		else if (action == 3)
		{
			ft_putstr(": realloc: ptr -> [0x");
			print_addr(history->ptr);
			ft_putstr("] - size -> [");
			print_size(history->size);
			ft_putstr("]\n");
		}
		else
		{
			ft_putstr(": reallocf: ptr -> [0x");
			print_addr(history->ptr);
			ft_putstr("] - size -> [");
			print_size(history->size);
			ft_putstr("]\n");
		}
		history = history->next;
		id++;
	}
}

void		show_alloc_history(void)
{
	memory_management_mutex(NULL, 0, 0, 7);
}
