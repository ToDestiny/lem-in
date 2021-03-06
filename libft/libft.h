/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:09:19 by acolas            #+#    #+#             */
/*   Updated: 2019/04/15 17:29:50 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LBITS 0x101010101010101L
# define HBITS 0x8080808080808080L

# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "ft_array.h"
# include "ft_process.h"
# include "ft_assoc.h"

# ifndef __uint128_t
#  define BIG_PIECE uintmax_t
# else
#  define BIG_PIECE __uint128_t
# endif

# define IF(a, b) if (a) b
# define EF(a, b) else if (a) b
# define EL(b) else b

# define OR(a, b) (a ? a : b)

# define SIZE(type, n) sizeof(type) * (n)

# define F ft_format
# define W ft_printf

/*
** Colors
*/
# define COLOR(color, string) "\e[" color "m" string "\e[0m"
# define RED(string) "\e[31m" string "\e[0m"
# define GREEN(string) "\e[32m" string "\e[0m"
# define YELLOW(string) "\e[33m" string "\e[0m"
# define BLUE(string) "\e[34m" string "\e[0m"
# define PURPLE(string) "\e[35m" string "\e[0m"
# define CYAN(string) "\e[36m" string "\e[0m"
# define BLACK(string) "\e[30m" string "\e[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
char				*ft_strcpy(char *dest, char *src);
void				ft_putstr(const char *s);
char				*ft_strncpy(char *dst, char *src, size_t len);
int8_t				ft_strcmp(char *s1, char *s2);
int8_t				ft_strncmp(char *s1, char *s2, size_t n);
int					ft_atoi(char *str);
char				*ft_strdup(char *str);
char				*ft_strndup(char *str, size_t n);
char				**ft_strsplit(char *str, char chr);
char				**ft_strfsplit(char *str, char chr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int8_t				ft_isnumeric(char *str);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(char *str, char chr);
char				*ft_strrchr(char *str, char chr);
size_t				ft_strchrcount(char *str, char chr);
void				*ft_mlc(size_t n);
void				*ft_free(int n, ...);
void				*ft_bzero(void *ptr, size_t n);
void				*ft_memset(void *ptr, uint8_t byte, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memchr(const void *mem, const unsigned char c,
					size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strndup(char *str, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *str1, char *str2);
char				*ft_strtrim(char const *s);
size_t				ft_strlen(char *str);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
int					ft_iterative_power(int n, int power);
int					ft_iterative_factorial(int n);
int					ft_sqrt(int n);
int					ft_is_prime(int n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list (*new));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_free_arr(char **a);
void				free(void *ptr);
t_assoc				*ft_assoc(size_t n);
intmax_t			ft_pow(intmax_t nb, uintmax_t pow);
uintmax_t			ft_upow(uintmax_t nb, uintmax_t pow);
intptr_t			ft_strchri(char *str, char chr);
intptr_t			ft_strrchri(char *str, char chr);
int					ft_strchri_lu(char *s, int c, int i);
size_t				ft_intlen(intmax_t num);
size_t				ft_uintlen(uintmax_t num, uint8_t base);
char				*ft_int_to_str(intmax_t num);
char				*ft_uint_to_str(uintmax_t num, uint8_t base);
char				*ft_unichr(int chr);

void				ft_init(int argc, char **argv, intmax_t options);
char				*ft_strfjoin(char *str1, char *str2, uint8_t f);
void				ft_free_strary(char **strary);
void				ft_separator(char *str);

ssize_t				ft_printf(char *format, ...);
ssize_t				ft_dprintf(int fd, char *format, ...);
char				*ft_format(char *format, ...);
ssize_t				ft_sformat(char **dest, char *format, ...);
void				ft_print_memory(void *ptr, size_t size);
void				ft_print_strary(char **strary);

void				*ft_array(size_t n);
void				*ft_any_array(size_t count, size_t n);
void				*ft_array_push(void *ary, void *ptr);
void				*ft_array_free(void *ary);

#endif
