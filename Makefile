# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <acolas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:54:15 by acolas            #+#    #+#              #
#    Updated: 2019/04/10 19:22:04 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRCS = srcs/main.c \
	srcs/ft_algorithm.c \
	srcs/ft_extra.c \
	srcs/ft_parsing.c \
	srcs/ft_moving_ants.c \
	srcs/ft_validate.c \
	srcs/ft_printing.c \
	srcs/ft_utilities.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
INCLUDES = -I libft/ -I ./includes
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) libft/libft.a  
		@$(CC) $(CFLAGS) -Llibft -lft $^ -o $@

%.o: %.c
	    @$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

libft/libft.a:
		@make -C libft

clean :
		@make -C libft clean
		@rm -rf $(OBJS)

fclean : clean
		@make -C libft fclean
		@rm -rf $(NAME)

re : fclean all
