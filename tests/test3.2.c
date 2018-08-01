/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 22:18:07 by vsteffen          #+#    #+#             */
/*   Updated: 2018/08/01 22:18:08 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define M (1024 * 1024)

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char	*addr1;
	char	*addr2;
	char	*addr3;

	addr1 = (char*)malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = (char*)malloc(16 * M);
	addr3 = (char*)realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
	return (0);
}
