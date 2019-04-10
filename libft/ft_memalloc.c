/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:20:47 by acolas            #+#    #+#             */
/*   Updated: 2019/04/10 19:01:33 by acolas           ###   ########.fr       */
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

void	*ft_mlc(size_t n)
{
	void	*ptr;

	if ((ptr = malloc(n)))
		return (ptr);
	if (g_process.options & MLC_ERROR)
		ft_dprintf(2, "Malloc: failed to allocate %U bytes.\n", n);
	if (g_process.options & MLC_EXIT)
		exit(0);
	return (0);
}

void	*ft_free(int n, ...)
{
	va_list	ap;

	if (n < 1)
		return (0);
	va_start(ap, n);
	while (n--)
		free(va_arg(ap, void*));
	va_end(ap);
	return (0);
}
