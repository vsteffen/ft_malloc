/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 22:07:46 by vsteffen          #+#    #+#             */
/*   Updated: 2018/08/01 22:07:48 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

int		main(int ac, char **av)
{
	char	*str;
	void	*ptr1;

	str = (char*)malloc(32);
	ptr1 = malloc(128);
	strcpy(str, "abcdefghijklmnopqrstuvxyzABCDEF");
	str[1] = (char)11;
	ptr1 = calloc(48, 1);
	ptr1 = realloc(ptr1, 32);
	ptr1 = reallocf(ptr1, 48);
	ptr1 = reallocf(ptr1, 64);
	free(ptr1);
	write(1, "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+", 59);
	write(1, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n", 37);
	show_alloc_mem();
	write(1, "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+", 59);
	write(1, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n", 37);
	show_alloc_mem_ex(str);
	write(1, "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+", 59);
	write(1, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n", 37);
	show_alloc_mem_ex(NULL);
	write(1, "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+", 59);
	write(1, "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n", 37);
	show_alloc_history();
	return (0);
}
