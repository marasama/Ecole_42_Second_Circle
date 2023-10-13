# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 04:33:34 by adurusoy          #+#    #+#              #
#    Updated: 2023/10/13 04:52:36 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

SRC = event.c fractal.c main.c tools.c event2.c tools2.c

OBJS = $(SRC:.c=.o)

MLX = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit

FT_PRNT = ./ft_printf/ftprintf.a


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(FT_PRNT) $(OBJS) $(MLX) -o $(NAME)

norm :
	norminette $(SRC) fractol.h ./ft_printf/*.c ./ft_printf/ft_printf.h

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
