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

OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)

CLI_OBJS := $(addprefix $(OBJ_DIR)/,$(SRC_CLT:.c=.o))
SRV_OBJS := $(addprefix $(OBJ_DIR)/,$(SRC_SRV:.c=.o))
CLI_DEPS := $(CLI_OBJS:.o=.d)
SRV_DEPS := $(SRV_OBJS:.o=.d)

all: $(PRINTF_A) $(OBJ_DIR) $(NAME_C) $(NAME_S)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -MMD -MP -c $< -o $@


$(NAME_S): $(SRV_OBJS) $(PRINTF_A)
	$(CC) $(CFLAGS) -o $@ $(SRV_OBJS) $(PRINTF_A)

$(NAME_C): $(CLI_OBJS) $(PRINTF_A)
	$(CC) $(CFLAGS) -o $@ $(CLI_OBJS) $(PRINTF_A)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

clean:
	-$(MAKE) -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	-$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean fclean re

-include $(CLI_DEPS) $(SRV_DEPS)