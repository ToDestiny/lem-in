/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:43:26 by acolas            #+#    #+#             */
/*   Updated: 2019/04/19 14:16:59 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	size_t	len;
	char	*res;

	if (!str || !n)
		return ((!str) ? 0 : ft_memalloc(sizeof(char)));
	len = ft_strlen(str);
	if (len < n)
		n = len;
	if (!(res = ft_memcpy(ft_mlc(SIZE(char, n + 1)), str, n)))
		return (0);
	res[n] = '\0';
	return (res);
}

char	*ft_strdup(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = ft_strlen(str) + 1;
	return (ft_memcpy(ft_mlc(SIZE(char, len)), str, len));
}
