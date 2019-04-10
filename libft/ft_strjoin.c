/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:23:52 by acolas            #+#    #+#             */
/*   Updated: 2019/04/10 18:27:16 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*dst;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		dst = (char *)malloc(sizeof(*dst) * (len + 1));
		if (dst == 0)
			return (NULL);
		ft_strcpy(dst, s1);
		ft_strcat(dst, s2);
		return (dst);
	}
	return (0);
}

char	*ft_strfjoin(char *str1, char *str2, uint8_t f)
{
	char	*res;

	res = ft_strjoin(str1, str2);
	if (f & 1)
		free(str1);
	if (f & 2)
		free(str2);
	return (res);
}