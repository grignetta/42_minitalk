# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadenko <dpadenko@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:45:38 by dpadenko          #+#    #+#              #
#    Updated: 2025/08/26 16:15:39 by dpadenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C=client
NAME_S=server
CC     := cc
CFLAGS := -Wall -Wextra -Werror

INCS := -I . \
		-I lib/printf \
		-I lib/printf/libft

PRINTF_DIR := lib/printf
PRINTF_A   := $(PRINTF_DIR)/libftprintf.a

SRC_CLT= client.c
SRC_SRV= server.c

CLI_OBJS := $(SRC_CLT:.c=.o)
SRV_OBJS := $(SRC_SRV:.c=.o)

all: $(PRINTF_A) $(NAME_C) $(NAME_S)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME_S): $(SRV_OBJS) $(PRINTF_A)
	$(CC) $(CFLAGS) -o $@ $(SRV_OBJS) $(PRINTF_A)

$(NAME_C): $(CLI_OBJS) $(PRINTF_A)
	$(CC) $(CFLAGS) -o $@ $(CLI_OBJS) $(PRINTF_A)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

clean:
	-$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(SRV_OBJS) $(CLI_OBJS)

fclean: clean
	-$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean fclean re
