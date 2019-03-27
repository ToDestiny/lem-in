/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:43:26 by acolas            #+#    #+#             */
/*   Updated: 2019/02/13 16:17:37 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy)
		ft_strcpy(copy, s1);
	return (copy);
}
