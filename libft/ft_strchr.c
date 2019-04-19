/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:23:36 by acolas            #+#    #+#             */
/*   Updated: 2019/04/15 17:23:38 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(char *str, char chr)
{
	if (!str || !chr)
		return (0);
	while (*str)
	{
		if (*str == chr)
			break ;
		str++;
	}
	return (*str == chr ? str : 0);
}

char		*ft_strrchr(char *str, char chr)
{
	char	*res;

	if (!str || !chr)
		return (0);
	res = 0;
	while (*str)
	{
		if (*str == chr)
			res = str;
		str++;
	}
	return (res);
}

intptr_t	ft_strchri(char *str, char chr)
{
	char	*res;

	if ((res = ft_strchr(str, chr)))
		return (res - str);
	return (-1);
}

intptr_t	ft_strrchri(char *str, char chr)
{
	char	*res;

	if ((res = ft_strrchr(str, chr)))
		return (res - str);
	return (-1);
}

size_t		ft_strchrcount(char *str, char chr)
{
	size_t	count;

	if (!str || !chr)
		return (0);
	count = 0;
	while (*str)
	{
		if (*str == chr)
			count++;
		str++;
	}
	return (count);
}
