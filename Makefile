# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 20:10:01 by tbeguin           #+#    #+#              #
#    Updated: 2020/02/04 02:23:56 by tbeguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC =  lib/ft_memset.c 	\
	   lib/ft_bzero.c 		\
	   lib/ft_memcpy.c 		\
	   lib/ft_memccpy.c 	\
	   lib/ft_memmove.c 	\
	   lib/ft_memchr.c 		\
	   lib/ft_memcmp.c 		\
	   lib/ft_strlen.c 		\
	   lib/ft_strdup.c 		\
	   lib/ft_strcpy.c		\
	   lib/ft_strncpy.c		\
	   lib/ft_strcat.c 		\
	   lib/ft_strncat.c 	\
	   lib/ft_strlcat.c 	\
	   lib/ft_strchr.c 		\
	   lib/ft_strrchr.c 	\
	   lib/ft_strstr.c 		\
	   lib/ft_strnstr.c 	\
	   lib/ft_strcmp.c 		\
	   lib/ft_strncmp.c 	\
	   lib/ft_atoi.c 		\
	   lib/ft_isalpha.c 	\
	   lib/ft_isdigit.c 	\
	   lib/ft_isalnum.c 	\
	   lib/ft_isascii.c 	\
	   lib/ft_isprint.c 	\
	   lib/ft_toupper.c 	\
	   lib/ft_tolower.c 	\
	   lib/ft_memalloc.c 	\
	   lib/ft_memdel.c		\
	   lib/ft_strnew.c		\
	   lib/ft_strdel.c		\
	   lib/ft_strclr.c		\
	   lib/ft_striter.c		\
	   lib/ft_striteri.c	\
	   lib/ft_strmap.c		\
	   lib/ft_strmapi.c		\
	   lib/ft_strequ.c		\
	   lib/ft_strnequ.c		\
	   lib/ft_strsub.c		\
	   lib/ft_strjoin.c		\
	   lib/ft_strtrim.c		\
	   lib/ft_strsplit.c	\
	   lib/ft_itoa.c		\
	   lib/ft_putchar.c		\
	   lib/ft_putstr.c		\
	   lib/ft_putendl.c		\
	   lib/ft_putnbr.c		\
	   lib/ft_putchar_fd.c	\
	   lib/ft_putstr_fd.c	\
	   lib/ft_putendl_fd.c	\
	   lib/ft_putnbr_fd.c	\
	   lib/ft_lstnew.c		\
	   lib/ft_lstdelone.c	\
	   lib/ft_lstdel.c		\
	   lib/ft_lstadd.c		\
	   lib/ft_lstiter.c		\
	   lib/ft_lstmap.c		\
	   lib/ft_islower.c		\
	   lib/ft_isupper.c		\
	   lib/ft_lstrev.c		\
	   lib/get_next_line.c	\
	   printf/ft_printf.c	\
	   printf/pf_buff.c		\
	   printf/pf_catch.c	\
	   printf/pf_check.c	\
	   printf/pf_ftoa.c		\
	   printf/pf_handeler_b.c	\
	   printf/pf_handeler_c.c	\
	   printf/pf_handeler_d.c	\
	   printf/pf_handeler_f.c	\
	   printf/pf_handeler_o.c	\
	   printf/pf_handeler_p.c	\
	   printf/pf_handeler_s.c	\
	   printf/pf_handeler_u.c	\
	   printf/pf_handeler_unknow.c	\
	   printf/pf_handeler_x.c	\
	   printf/pf_handeler_xup.c	\
	   printf/pf_itoa_base.c	\
	   printf/pf_print.c	\
	   printf/pf_set.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all : $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/lib
	@mkdir -p $(OBJ_DIR)/printf

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mLibft Created\033[0m"

clean : 
	@rm -Rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mRemoved Libft\033[0m"

re : fclean all

.PHONY : all clean fclean re
