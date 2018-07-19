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
# include <pthread.h>

# define TINY 256
# define SMALL 1040
# define DEBUG 0

typedef struct			s_block_mem {
	uintptr_t			mem_align;
	size_t				size;
	int8_t				used;
	int8_t				new_page;
	struct s_block_mem	*next;
}						t_block_mem;

extern t_block_mem		*g_mem[3];

extern pthread_mutex_t	g_mutex;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);

void			show_alloc_mem();

int8_t			get_zone(size_t size_requested);
void			set_metadata(t_block_mem *mem, size_t size_requested, t_block_mem *next_block);
void			set_metadata_next_block(t_block_mem *mem, t_block_mem *next_block);

int8_t			isset_addr(void *ptr);
void			*mutex_unlock_with_ptr(void *ptr);
void			start_free(void *ptr);
void			*start_malloc(size_t size);

void			print_size(size_t n);
void			print_addr(void *ptr);
void			print_debug_size_t(size_t debug, char *name);
void			print_debug_addr(void *debug, char *name);
void			print_debugf_size_t(size_t debug, char *name);
void			print_debugf_addr(void *debug, char *name);

#endif
