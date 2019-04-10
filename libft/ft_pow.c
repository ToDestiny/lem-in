/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 22:28:37 by bsouchet          #+#    #+#             */
/*   Updated: 2019/04/10 18:52:46 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_pow(intmax_t nb, uintmax_t pow)
{
	intmax_t res;

	if (pow < 1)
		return (pow ? 0 : 1);
	res = 1;
	while (pow--)
		res *= nb;
	return (res);
}

uintmax_t	ft_upow(uintmax_t nb, uintmax_t pow)
{
	uintmax_t res;

	if (pow < 1)
		return (pow ? 0 : 1);
	res = 1;
	while (pow--)
		res *= nb;
	return (res);
}
