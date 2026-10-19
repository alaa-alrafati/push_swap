# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 12:26:34 by aalrofat          #+#    #+#              #
#    Updated: 2025/11/26 12:26:48 by aalrofat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c create_stack.c ft_split.c errors.c swap_commands.c rotate_commands.c reverse_rotate_commands.c \
		push_commands.c sorted_3_nodes.c sorted_45_nodes.c create_stack_for_radix.c radix_algorathem.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
