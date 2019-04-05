# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <acolas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:54:15 by acolas            #+#    #+#              #
#    Updated: 2019/04/05 17:12:05 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRCS = srcs/main.c \
	srcs/algorithm.c \
	srcs/extra.c \
	srcs/lists_creation.c \
	srcs/moving_ants.c \
	srcs/queue_functions.c \
	srcs/validation.c \
	srcs/memory_cleaning.c \
	srcs/functions1.c \
	srcs/functions2.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
INCLUDES = -I libft/ -I ./includes
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) libft/libft.a  
		$(CC) $(CFLAGS) -Llibft -lft $^ -o $@

%.o: %.c
	    $(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

libft/libft.a:
		make -C libft

clean :
		make -C libft clean
		rm -rf $(OBJS)

fclean : clean
		make -C libft fclean
		rm -rf $(NAME)

re : fclean all
