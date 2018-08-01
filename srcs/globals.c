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
t_histo_global	*g_history = NULL;
int8_t			g_env = 0;

void			set_env_var(int8_t *g_env)
{
	const char	*verbose = getenv("FT_MALLOC_VERBOSE");
	const char	*history = getenv("FT_MALLOC_HISTORY");

	if (verbose)
	{
		if (ft_strcmp(verbose, "1") == 0 || ft_strcmp(verbose, "y") == 0 || \
			ft_strcmp(verbose, "yes") == 0)
		{
			*g_env = 1;
		}
	}
	if (history)
	{
		if (ft_strcmp(history, "1") == 0 || ft_strcmp(history, "y") == 0 || \
			ft_strcmp(history, "yes") == 0)
		{
			*g_env = *g_env | (1 << 1);
		}
	}
}
