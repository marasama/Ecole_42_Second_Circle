# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 13:56:31 by adurusoy          #+#    #+#              #
#    Updated: 2023/10/12 21:00:15 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_bzero.c \
		ft_pf_hex.c \
		ft_pf_int.c \
		ft_pf_intlen.c \
		ft_pf_pointer.c \
		ft_pf_putchar.c \
		ft_pf_string.c \
		ft_pf_unint.c \
		ft_pow.c

OBJS = $(SRCS:.c=.o)

CC = gcc

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) -c $(FLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
