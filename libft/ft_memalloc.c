/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:20:47 by acolas            #+#    #+#             */
/*   Updated: 2019/02/05 01:10:48 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	index;

	index = 0;
	ptr = malloc(size);
	while (ptr && index < size)
	{
		((char *)ptr)[index] = 0;
		index++;
	}
	return (ptr);
}
