# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:45:38 by dpadenko          #+#    #+#              #
#    Updated: 2024/02/21 14:04:10 by dpadenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C=client
NAME_S=server
CC=cc
FLAGS=-Werror -Wextra -Wall -g

SRC_C= client.c
SRC_S= server.c

LIBDIR=./libft
PRINTFDIR = ./printf
LIBFT = ${LIBDIR}/libft.a
PRINTF = ${PRINTFDIR}/libftprintf.a

OBJ_C = ${SRC_C:.c=.o}
OBJ_S = ${SRC_S:.c=.o}

all: all_C all_S

all_C: $(NAME_C)
all_S: $(NAME_S)

%.o: %.c
		${CC} ${FLAGS} -o $@ -c $< -I . -I $(PRINTFDIR)

${NAME_C}: ${LIBFT} ${OBJ_C}
		${CC} ${FLAGS} ${OBJ_C} -L${LIBDIR} -lft -o ${NAME_C}

${NAME_S}: ${PRINTF} ${OBJ_S}
		${CC} ${FLAGS} ${OBJ_S} -L${PRINTFDIR} -lftprintf -o ${NAME_S}

${LIBFT}:
		${MAKE} -C ${LIBDIR} all

${PRINTF}:
		${MAKE} -C ${PRINTFDIR} all

.PHONY: clean fclean all re

clean:
	${MAKE} -C ${LIBDIR} clean
	${MAKE} -C ${PRINTFDIR} clean
	rm -f ${OBJ_C} ${OBJ_S}

fclean: clean
	${MAKE} -C ${LIBDIR} fclean
	${MAKE} -C ${PRINTFDIR} fclean
	rm -rf ${NAME_C}
	rm -rf ${NAME_S}

re: fclean all