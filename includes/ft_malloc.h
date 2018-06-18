/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:37:16 by vsteffen          #+#    #+#             */
/*   Updated: 2018/06/18 19:39:08 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "libft.h"
# include <sys/mman.h>
# include <stdlib.h>
# include <unistd.h>

static void		*g_mem = NULL;

typedef struct	s_block_mem {
	size_t		size;
}				t_block_mem;

// typedef struct		s_project {
// 	t_elem			*elem;
// 	t_elem			*current;
// 	t_elem			*last;
// }					t_project;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

#endif
