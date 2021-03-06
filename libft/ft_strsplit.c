/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:47:54 by acolas            #+#    #+#             */
/*   Updated: 2019/04/19 14:19:23 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_strsplit(char *str, char chr)
{
	size_t	wc;
	char	**res;
	char	*tmp;

	if (!str || !chr || !(wc = ft_strchrcount(str, chr)))
		return (0);
	if (!(res = ft_mlc(sizeof(char*) * (wc + 2))))
		return (0);
	wc = 0;
	while (*str)
	{
		tmp = str;
		while (*str && *str != chr)
			str++;
		res[wc] = ft_memcpy(ft_mlc(SIZE(char, str - tmp)), tmp, str - tmp);
		res[wc++][str - tmp] = '\0';
		if (!*str)
			break ;
		str++;
	}
	res[wc] = 0;
	return (res);
}

void	ft_free_strary(char **strary)
{
	char **tmp;

	tmp = strary;
	if (!strary)
		return ;
	while (*strary)
		free(*strary++);
	free(tmp);
}

char	**ft_strfsplit(char *str, char chr)
{
	size_t	wc;
	char	**res;

	if (!str || !chr || !(wc = ft_strchrcount(str, chr)))
		return (0);
	if (!(res = ft_mlc(sizeof(char*) * (wc + 2))))
		return (0);
	wc = 0;
	while (*str)
	{
		res[wc++] = str;
		while (*str && *str != chr)
			str++;
		if (!*str)
			break ;
		*str++ = '\0';
	}
	res[wc] = 0;
	return (res);
}
