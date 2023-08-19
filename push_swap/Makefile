# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 05:17:00 by adurusoy          #+#    #+#              #
#    Updated: 2023/08/19 21:50:52 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/*.c

PRINTF = ./ft_printf/*.c

OPERATIONS = ./operations/*.c

SRCS =	check_funcs.c \
		cost_funcs.c \
		cost_funcs2.c \
		sort_funcs.c \
		push_swap.c \
		sort_funcs2.c

CHECKER =	checker.c \
			check_funcs.c \
			checker_utils.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(PRINTF) $(LIBFT) $(OPERATIONS) $(SRCS) $(FLAGS)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)
	rm -f checker

bonus:
	gcc -o checker $(CHECKER) $(PRINTF) $(LIBFT) $(OPERATIONS)  $(FLAGS)

re: fclean all

.PHONY: all clean fclean re
