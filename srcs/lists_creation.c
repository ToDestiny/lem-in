/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:31:20 by acolas            #+#    #+#             */
/*   Updated: 2019/04/02 11:39:33 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_params(char **av)
{
	if (!av)
		return (0);
	if (!ft_strcmp(av[1], "--leaks"))
		return (1);
	else if (!ft_strcmp(av[1], "--silent"))
		return (2);
	else if(!ft_strcmp(av[1], "--paths"))
		return (3);
	else if (!ft_strcmp(av[1], "--moves"))
		return (4);
	else
		return (0);	
}