/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:23:52 by acolas            #+#    #+#             */
/*   Updated: 2019/04/19 14:17:15 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	char	*res_tmp;

	if (!str1 || !str2)
		return (ft_strdup(str1 ? str1 : str2));
	if (!(res = ft_mlc(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (0);
	res_tmp = res;
	while (*str1)
		*res++ = *str1++;
	while (*str2)
		*res++ = *str2++;
	*res = '\0';
	return (res_tmp);
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
