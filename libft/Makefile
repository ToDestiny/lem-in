# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 14:27:26 by acolas            #+#    #+#              #
#    Updated: 2019/04/10 17:54:58 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_putchar.c \
	  ft_strlen.c \
	  ft_strcpy.c \
	  ft_putstr.c \
	  ft_strncpy.c \
	  ft_strcmp.c \
	  ft_atoi.c \
	  ft_strdup.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memccpy.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstdelone.c \
	  ft_iterative_power.c \
	  ft_iterative_factorial.c \
	  ft_intlen.c \
	  ft_sqrt.c \
	  ft_is_prime.c \
	  ft_isnumeric.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  get_next_line.c \
	  ft_free_arr.c \
	  ft_printf.c \
	  ft_match.c \
	  ft_number.c \
	  ft_parse.c \
	  ft_simple.c \
	  ft_tools.c \
	  ft_pow.c \
	  ft_process.c \
	  ft_other.c \
	  ft_print_memory.c \
	  ft_int_to_str.c \
	  ft_unicode.c \
	  ft_array.c \

INC = -I includes/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$ $(CC) $(CFLAGS) -c $(SRC)
	@$ ar -rc $(NAME) $(OBJ)
	@$ ranlib $(NAME)

clean:
	@$ /bin/rm -f $(OBJ)

fclean: clean
	@$ /bin/rm -f $(NAME)

re: fclean all

