/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:40:36 by vsteffen          #+#    #+#             */
/*   Updated: 2018/07/23 23:40:38 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_block_mem		*g_mem[3] = { NULL };
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;
t_histo_mem		*g_history = NULL;
