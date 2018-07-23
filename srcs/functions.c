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

uint8_t	count_numeral_base16_malloc(uintptr_t nb)
{
	uint8_t		count;

	count = 1;
	while (nb /= 16)
		++count;
	return (count);
}

void	ft_ptoa_base_malloc(uintptr_t nb, char *output)
{
	size_t		length;
	char		*alph;

	alph = "0123456789ABCDEF";
	length = (size_t)count_numeral_base16_malloc(nb);
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
