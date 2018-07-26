#include "ft_malloc.h"

void		add_alloc_history(int8_t action, void *ptr, size_t size)
{
	t_histo_mem		*history;
	t_histo_mem		*last_history;

	history = (t_histo_mem*)mmap(0, get_size_page(sizeof(t_histo_mem), 2), \
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if ((void*)history == MAP_FAILED)
		return ;
	history->action = action;
	history->ptr = ptr;
	history->size = size;
	if (!g_history)
		g_history = history;
	else
	{
		last_history = g_history;
		while (last_history->next)
			last_history = last_history->next;
		last_history->next = history;
	}

}

void		print_history(void)
{
	t_histo_mem		*history;
	size_t			id;
	int8_t			action;

	history = g_history;
	id = 1;
	while (history)
	{
		action = history->action;
		ft_putnbr(id);
		if (action == 0)
		{
			ft_putstr(": calloc (size -> ");
			print_size(history->size);
			ft_putstr(")\n");
		}
		else if (action == 1)
		{
			ft_putstr(": free (ptr -> 0x");
			print_addr(history->ptr);
			ft_putstr(")\n");
		}
		else if (action == 2)
		{
			ft_putstr(": malloc (size -> ");
			print_size(history->size);
			ft_putstr(")\n");
		}
		else if (action == 3)
		{
			ft_putstr(": realloc (ptr -> 0x");
			print_addr(history->ptr);
			ft_putstr(" /// size -> ");
			print_size(history->size);
			ft_putstr(")\n");
		}
		else
		{
			ft_putstr(": reallocf (ptr -> 0x");
			print_addr(history->ptr);
			ft_putstr(" /// size -> ");
			print_size(history->size);
			ft_putstr(")\n");
		}
		history = history->next;
		id++;
	}
}

void		show_alloc_history(void)
{
	memory_management_mutex(NULL, 0, 0, 7);
}
