/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:48:58 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/23 23:49:00 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void			print_addr(void *ptr)
{
	uint8_t		length;
	char		*output;
	uintptr_t	uip;

	uip = (uintptr_t)ptr;
	length = ptoa_count_numeral_base16_malloc(uip) + 1;
	output = (char *)mmap(0, get_size_page(length, 2), \
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if ((void*)output == MAP_FAILED)
		return ;
	ft_ptoa_base_malloc(uip, output);
	ft_putstr(output);
	if (munmap((void*)output, get_size_page(length, 2)) == 0)
		(void)ptr; // success
	else
		(void)ptr; // failed
}

void			print_size(size_t n)
{
	if (n >= 10)
	{
		print_size(n / 10);
		print_size(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void			print_block_mem(t_block_mem *mem)
{
	ft_putstr("0x");
	print_addr((void *)mem + sizeof(t_block_mem));
	ft_putstr(" - 0x");
	print_addr((void *)mem + sizeof(t_block_mem) + mem->size);
	ft_putstr(" : ");
	print_size(mem->size);
	ft_putstr(" octets\n");
}

void			print_zone(t_block_mem *mem, char *zone, size_t *total)
{
	if (mem != NULL)
	{
		ft_putstr(zone);
		ft_putstr(" : 0x");
		print_addr((void *)mem);
		ft_putchar('\n');
		while (mem != NULL)
		{
			if (mem->used == 1)
			{
				print_block_mem(mem);
				*total += mem->size;
			}
			mem = mem->next;
		}
	}
	else
	{
		ft_putstr(zone);
		ft_putstr(" : not used\n");
	}
}

void			show_alloc_mem(void)
{

	memory_management_mutex(NULL, 0, 0, 5);
}
