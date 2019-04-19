/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 22:28:17 by bsouchet          #+#    #+#             */
/*   Updated: 2019/04/19 14:13:37 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_bzero2(void *ptr, size_t n)
{
	uint8_t	*tmp;

	tmp = (uint8_t*)ptr;
	while (n--)
		*tmp++ = 0;
	return (ptr);
}

void		*ft_bzero(void *ptr, size_t n)
{
	BIG_PIECE	*big;
	size_t		i;

	if (!ptr)
		return (0);
	i = n % sizeof(BIG_PIECE);
	n /= sizeof(BIG_PIECE);
	big = (BIG_PIECE*)ptr;
	while (n--)
		*big++ = 0;
	if (i)
		ft_bzero2(big, i);
	return (ptr);
}
