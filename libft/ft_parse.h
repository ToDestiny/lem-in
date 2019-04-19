/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:36:25 by ybereshc          #+#    #+#             */
/*   Updated: 2019/04/19 14:16:48 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include "libft.h"
# include "ft_match.h"

# define BUFF_SIZE 512

typedef struct	s_parse
{
	ssize_t	len;
	int		i;
	char	buff[BUFF_SIZE];
	int		fd;
	char	**dest;
}				t_parse;

t_parse	g_p;
va_list	g_ap;
void	(*g_func)(char*, int, int8_t);

void			str_format(char *format);
void			push(char *src, int len, int8_t to_free);
void			form(char *src, int len, int8_t to_free);
char			*match(char *str);

#endif
