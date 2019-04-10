/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:05:45 by acolas            #+#    #+#             */
/*   Updated: 2019/04/10 19:05:51 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintlen(uintmax_t num, uint8_t base)
{
	size_t	len;

	if (!base)
		return (0);
	len = 1;
	while (num /= base)
		len++;
	return (len);
}

size_t	ft_intlen(intmax_t num)
{
	return (ft_uintlen((num < 0 ? -num : num), 10) + (num < 0));
}
