/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:33:20 by acolas            #+#    #+#             */
/*   Updated: 2019/04/15 17:27:55 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int8_t	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		return (0);
	while (--n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int8_t	ft_strcmp(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, -1));
}

int8_t	ft_strnequ(char *str1, char *str2, size_t n)
{
	return (!ft_strncmp(str1, str2, n));
}

int8_t	ft_strequ(char *str1, char *str2)
{
	return (!ft_strcmp(str1, str2));
}
