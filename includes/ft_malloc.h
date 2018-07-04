/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:37:16 by vsteffen          #+#    #+#             */
/*   Updated: 2018/06/19 18:46:09 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "libft.h"
# include <sys/mman.h>
# include <stdlib.h>
# include <unistd.h>

# define TINY 1
# define SMALL 16

typedef struct			s_block_mem {
	size_t				size;
	int8_t				used;
	struct s_block_mem	*next;
}						t_block_mem;

extern t_block_mem		*g_mem[3];

// typedef struct		s_project {
// 	t_elem			*elem;
// 	t_elem			*current;
// 	t_elem			*last;
// }					t_project;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);

void			show_alloc_mem();


void			printsize(size_t n);
void			print_addr(void *ptr);
void			print_debug(size_t debug, char *name);

#endif
