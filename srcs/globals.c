#include "ft_malloc.h"

t_block_mem		*g_mem[3] = { NULL };
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;
