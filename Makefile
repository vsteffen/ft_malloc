# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:52:05 by vsteffen          #+#    #+#              #
#    Updated: 2018/03/20 18:17:27 by vsteffen         ###   ########.fr        #
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
LPATH	=	$(LIBFT)/libft.a
HPATH 	=	-I $(ROOT)/includes -I $(LIBFT)/includes

SRC =	malloc.c \
		realloc.c \
		free.c

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
	@echo "Deleting lib content."
	@$(MAKE) $(LIBFT) fclean
	@echo "\033[32mLib content deleted.\033[0m\n"


re: fclean all
