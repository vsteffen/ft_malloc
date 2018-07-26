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

# define TINY 128
# define SMALL 1024
# define DEBUG 0

typedef struct			s_block_mem {
	uintptr_t			mem_align;
	size_t				size;
	int8_t				used;
	int8_t				new_page;
	struct s_block_mem	*next;
}						t_block_mem;

extern			t_block_mem		*g_mem[3];
extern			pthread_mutex_t	g_mutex;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem();

size_t			get_size_page(size_t size_requested, int8_t zone);
int8_t			get_zone(size_t size_requested);
void			set_metadata(t_block_mem *mem, size_t size_requested, t_block_mem *next_block);
void			set_metadata_next_block(t_block_mem *mem, t_block_mem *next_block);
void			*create_new_page(size_t size_requested, int8_t zone);


t_block_mem		*isset_addr_and_get_previous(void *ptr);
void			*mutex_unlock_with_ptr(void *ptr);
void			start_free(void *ptr);
void			*start_malloc(size_t size);
void			*start_realloc(void *ptr, size_t size);
void			print_zone(t_block_mem *mem, char *zone, size_t *total);

void			ft_ptoa_base_malloc(uintptr_t nb, char *output);
uint8_t			ptoa_count_numeral_base16_malloc(uintptr_t nb);

void			show_alloc_mem_dump(void *ptr);
void			print_block_mem(t_block_mem *mem);
void			ft_byte_dump_base(int8_t byte, char *output, int8_t base, int8_t flag_isprint);

void			*memory_management_mutex(void *ptr, size_t size, size_t count, int8_t action);

void			print_size(size_t n);
void			print_addr(void *ptr);

void			print_debug_size_t(size_t debug, char *name);
void			print_debug_addr(void *debug, char *name);
void			print_debugf_size_t(size_t debug, char *name);
void			print_debugf_addr(void *debug, char *name);

#endif
