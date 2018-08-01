/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:11:10 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/23 17:11:15 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

uint8_t		ptoa_count_numeral_base16_malloc(uintptr_t nb)
{
	uint8_t		count;

	count = 1;
	while (nb /= 16)
		++count;
	return (count);
}

void		ft_ptoa_base_malloc(uintptr_t nb, char *output)
{
	uint8_t		length;
	char		*alph;

	alph = "0123456789ABCDEF";
	length = ptoa_count_numeral_base16_malloc(nb);
	output[length] = '\0';
	while (nb != 0)
	{
		length--;
		output[length] = alph[nb % 16];
		nb /= 16;
	}
	if (length > 0)
	{
		while (--length > 0)
			output[length] = '0';
		output[0] = '0';
	}
}

void		ft_ptoa_base_show_ex(uintptr_t nb, char *output)
{
	uint8_t		length;
	char		*alph;

	alph = "0123456789ABCDEF";
	length = 16;
	while (nb != 0)
	{
		length--;
		output[length] = alph[nb % 16];
		nb /= 16;
	}
	if (length > 0)
	{
		while (--length > 0)
			output[length] = '0';
		output[0] = '0';
	}
}

int8_t		ft_byte_dump_base_length(int8_t *base, int8_t flag_isprint)
{
	if (*base == 10)
	{
		if (flag_isprint)
			return (2);
		return (3);
	}
	if (*base == 8)
		return (3);
	*base = 16;
	return (1);
}

void		ft_byte_dump_base(int8_t byte, char *output, int8_t base, \
	int8_t flag_isprint)
{
	int8_t		length;
	char		*alph;

	if (base == 10 && flag_isprint)
	{
		if (ft_isprint((int)byte))
			output[0] = (char)byte;
		else
			output[0] = '.';
		return ;
	}
	alph = "0123456789abcdef";
	length = ft_byte_dump_base_length(&base, flag_isprint);
	while (byte != 0)
	{
		output[length] = alph[byte % base];
		byte /= base;
		length--;
	}
	if (length >= 0)
	{
		output[length] = '0';
		while (--length >= 0)
			output[length] = '0';
	}
}
