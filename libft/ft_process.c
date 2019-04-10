/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:53:24 by acolas            #+#    #+#             */
/*   Updated: 2019/04/10 18:27:11 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "libft.h"

void	ft_init(int argc, char **argv, intmax_t options)
{
	if ((g_process.name = ft_strrchr(*argv, '/') + 1) == (char*)1)
		g_process.name = *argv;
	g_process.argc = argc - 1;
	g_process.argv = argv + 1;
	g_process.options = options;
}
