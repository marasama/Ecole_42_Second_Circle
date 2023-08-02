# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 17:03:19 by adurusoy          #+#    #+#              #
#    Updated: 2023/08/02 17:03:19 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minitalk

SV_SRC =	server.c

PRNT_SRC =	./ft_printf/*.c

CL_SRC =	client.c

FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):
		gcc -o server $(SV_SRC) $(PRNT_SRC) $(FLAGS)
		gcc -o client $(CL_SRC) $(PRNT_SRC) $(FLAGS)

clean:
	rm -f server
	rm -f client

fclean:	clean
	rm -f server
	rm -f client

re: fclean all

.PHONY: all clean fclean re
