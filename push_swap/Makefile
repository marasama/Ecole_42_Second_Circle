# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 05:17:00 by adurusoy          #+#    #+#              #
#    Updated: 2023/08/15 23:00:08 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = ./ft_printf/*.c

OPERATIONS = ./operations/*.c

SRCS = ./*.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(PRINTF) $(OPERATIONS) $(SRCS) $(FLAGS)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
