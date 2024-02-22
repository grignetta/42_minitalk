# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 14:00:45 by dpadenko          #+#    #+#              #
#    Updated: 2023/09/28 14:01:19 by dpadenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

LIBDIR = ./libft
LIBFT = ${LIBDIR}/libft.a

SRC = ft_printf.c ft_print_char.c ft_print_digit.c ft_print_hex.c \
	ft_print_ptr.c ft_print_str.c ft_print_undigit.c

OBJ = ${SRC:.c=.o}

%.o: %.c
		${CC} ${CFLAGS} -o $@ -c $< -I .

${NAME}: ${LIBFT} ${OBJ}
		cp ${LIBFT} ${NAME}
		ar -rcs $@ ${OBJ}

${LIBFT}:
		${MAKE} -C ${LIBDIR} all

all: ${NAME}

.PHONY: clean fclean all re

clean: 
		${MAKE} -C ${LIBDIR} clean
		rm -f ${OBJ} ${OBJ_B}

fclean: clean
		${MAKE} -C ${LIBDIR} fclean
		rm -rf ${NAME}

re: fclean all
