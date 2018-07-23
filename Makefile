# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:52:05 by vsteffen          #+#    #+#              #
#    Updated: 2018/07/23 17:25:57 by vsteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC 		=	/usr/bin/clang
RM 		=	/bin/rm
MAKE 	=	/usr/bin/make -C
MKDIR 	=	/bin/mkdir -p
AR 		=	/usr/bin/ar
RANLIB 	=	/usr/bin/ranlib
GIT		=	/usr/bin/git

OBJ = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror -g

LIB		=	$(ROOT)/lib
LIBSRCS	=	$(ROOT)/libsrcs
LIBFT 	=	$(LIBSRCS)/libft

ROOT  	=	$(shell /bin/pwd)
OPATH 	=	$(ROOT)/objs
CPATH 	=	$(ROOT)/srcs
LPATH	=	$(LIBFT)/libft.a -lpthread
HPATH 	=	-I $(ROOT)/includes -I $(LIBFT)/includes

SRC =	malloc.c \
	realloc.c \
	calloc.c \
	free.c \
	show_alloc_mem.c \
	globals.c \
	functions.c \
	memory_manager.c \
	block_getters_and_setters.c \
	print_debug.c

.PHONY: all clean fclean re

all: pre-check-submodule pre-check-lib $(NAME)

pre-check-submodule:
	@echo "\n\033[33m\033[4m\033[1m → ft_malloc \"Pre check submodule\"\033[0m"
	@echo "Update submodules"
	@$(GIT) submodule init
	@$(GIT) submodule update --recursive --remote

pre-check-lib:
	@echo "\n\033[33m\033[4m\033[1m → ft_malloc \"Pre check lib\"\033[0m"
	@echo "Compile or verify lib"
	@$(MAKE) $(LIBFT)

$(NAME): $(OPATH) $(OBJ)
	@echo "\n\033[33m\033[4m\033[1m → ft_malloc \"Make\"\033[0m"
	@echo "Building $@"
	@$(CC) -shared -o $@ $(CFLAGS) $(OBJ) $(LPATH) $(HPATH)
	$(RM) -f libft_malloc.so
	@ln -s $@ libft_malloc.so
	@echo "Generate tests"
	@$(CC) -o "ft_malloc" tests/ft_malloc.c libft_malloc.so
	@$(CC) -o test0 ./tests/test0.c
	@$(CC) -o test1 ./tests/test1.c
	@$(CC) -o test2 ./tests/test2.c
	@$(CC) -o test3.1 ./tests/test3.1.c
	@$(CC) -o test3.2 ./tests/test3.2.c
	@$(CC) -o test4 ./tests/test4.c
	@$(CC) -o test5 ./tests/test5.c libft_malloc.so
	@echo "\033[32m ╔════════════════╗"
	@echo " ║  All is done ! ║"
	@echo " ╚════════════════╝\033[0m"

$(OPATH)/%.o: $(CPATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HPATH)

$(OPATH):
	@echo "\n\033[33m\033[4m\033[1m → ft_malloc \"Building objs\"\033[0m"
	@echo "Creating OBJ directory"
	@$(MKDIR) $@
	@echo "Creating OBJ files if they do not exist or have changed"

clean:
	@echo "\n\033[33m\033[4m\033[1m → ft_malloc \"Clean\"\033[0m"
	@echo "Deleting OBJS."
	$(RM) -Rf $(OPATH)
	@echo "\033[32mOBJS deleted.\033[0m\n"

fclean: clean
	@echo "\n\033[33m\033[4m\033[1m → ft_malloc \"Fclean\"\033[0m"
	@echo "Deleting $(NAME)."
	$(RM) -f $(NAME)
	@echo "Deleting symbolic link \"libft_malloc.so\"."
	$(RM) -f libft_malloc.so
	@echo "\033[32m$(NAME) deleted.\033[0m\n"
	@echo "Deleting test files."
	$(RM) -f ft_malloc
	$(RM) -f test0
	$(RM) -f test1
	$(RM) -f test2
	$(RM) -f test3.1
	$(RM) -f test3.2
	$(RM) -f test4
	$(RM) -f test5
	@echo "\033[32mTest files deleted.\033[0m\n"

libft:
	@$(MAKE) $(LIBFT) fclean
	@$(MAKE) $(LIBFT)

re: fclean all
