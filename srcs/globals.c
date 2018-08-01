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
	const char	*var_env = getenv("FT_MALLOC_VERBOSE");

	if (var_env)
	{
		if (ft_strcmp(var_env, "1") == 0 || ft_strcmp(var_env, "y") == 0 || \
			ft_strcmp(var_env, "yes") == 0)
		{
			*g_env = 1;
			return ;
		}
	}
	*g_env = 0;
	return ;
}
