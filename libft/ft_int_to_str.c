/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:54:10 by acolas            #+#    #+#             */
/*   Updated: 2019/04/10 18:54:15 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uint_to_str(uintmax_t num, uint8_t base)
{
	size_t	len;
	char	*res;

	if (base < 2 || base > 36 || !(len = ft_uintlen(num, base)))
		return (0);
	if (!num)
		return (ft_strdup("0"));
	if (!(res = ft_mlc(len + 1)))
		return (0);
	res[len] = '\0';
	while (len--)
	{
		res[len] = num % base + 48;
		num /= base;
		if (res[len] > 57)
			res[len] += 39;
	}
	return (res);
}

char	*ft_int_to_str(intmax_t num)
{
	uintmax_t	ul;
	char		*res;

	ul = (num < 0) ? -num : num;
	if (!(res = ft_uint_to_str(ul, 10)))
		return (0);
	if (num < 0)
		return (ft_strfjoin("-", res, 2));
	return (res);
}
