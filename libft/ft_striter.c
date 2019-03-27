/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:07:23 by acolas            #+#    #+#             */
/*   Updated: 2017/05/02 16:07:26 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;
	int		len;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			(*f)((s + i));
			i++;
		}
	}
}
