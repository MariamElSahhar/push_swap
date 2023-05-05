# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melsahha <melsahhastudent.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 21:02:31 by melsahha          #+#    #+#              #
#    Updated: 2023/04/06 19:50:00 by melsahha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PRINTF_DIR = libft/
PRINTF_LIB = libftprintf.a
INCL = ./include/
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c push_swap.c stack_rules.c stack_utils.c parse_input.c parse_input2.c moves.c utils.c sort_n.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


$(NAME): $(OBJ) $(OBJ_DIR)
	@echo "Making libftprintf..."
	make -sC $(PRINTF_DIR)
	mv $(addprefix $(PRINTF_DIR), $(PRINTF_LIB)) .
	@echo "libftprintf done."
	@echo "Making push_swap..."
	$(CC) $(CFLAGS) $(OBJ) -L. -lftprintf -o $(NAME)
	@echo "push_swap done."

all: $(NAME)

$(OBJ_DIR)/%.o:%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -I$(INCL) $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR)
	make -sC $(PRINTF_DIR) clean
	rm -f $(PRINTF_LIB)

fclean: clean
	rm -f $(NAME)

re: fclean all

phone: re clean fclean $(NAME)
