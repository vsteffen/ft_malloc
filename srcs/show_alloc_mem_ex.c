/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:28:23 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/26 15:28:35 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		print_memory_user(t_block_mem *mem, char *output, size_t size_read)
{
	int8_t	*data;
	uint8_t	i;
	uint8_t	j;

	data = (int8_t*)(((void*)(mem)) + sizeof(t_block_mem));
	size_read = 0;
	while (mem->size > size_read)
	{
		ft_ptoa_base_show_ex((uintptr_t)data, output);
		i = 0;
		j = 0;
		while (i < 16)
		{
			if (i == 8)
				j++;
			ft_byte_dump_base(data[i], output + 18 + i + j, 16, 0);
			ft_byte_dump_base(data[i], output + 69 + i, 10, 1);
			j += 2;
			output[18 + i + j] = ' ';
			i++;
		}
		ft_putstr(output);
		size_read += 16;
		data = data + 16;
	}
}

void		prepare_output(char *output)
{
	output[16] = ' ';
	output[17] = ' ';
	output[42] = ' ';
	output[67] = ' ';
	output[68] = '|';
	output[85] = '|';
	output[86] = '\n';
	output[87] = '\0';
}

void		print_all_memory_user(char *output)
{
	t_block_mem		*mem;
	int8_t			i;

	i = 0;
	while (i < 3)
	{
		mem = g_mem[i];
		while (mem)
		{
			if (mem->used == 1)
			{
				print_block_mem(mem);
				print_memory_user(mem, output, 0);
			}
			mem = mem->next;
		}
		i++;
	}
}

void		show_alloc_mem_dump(void *ptr)
{
	t_block_mem		*mem;
	char			*output;

	output = (char*)mmap(0, get_size_page(96, 2),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if ((void*)output == MAP_FAILED)
		return ;
	prepare_output(output);
	if (ptr && isset_addr_and_get_previous(ptr))
	{
		mem = (t_block_mem *)(ptr - sizeof(t_block_mem));
		print_block_mem(mem);
		print_memory_user(mem, output, 0);
	}
	else
		print_all_memory_user(output);
	if (munmap(output, get_size_page(96, 2)) == 0)
		(void)ptr;
	else
		(void)ptr;
}

void		show_alloc_mem_ex(void *ptr)
{
	memory_management_mutex(ptr, 0, 0, 6);
}
