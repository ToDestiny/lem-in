/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:45:39 by acolas            #+#    #+#             */
/*   Updated: 2019/04/04 15:10:00 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			all_at_end(t_list *ants)
{
	t_ant	*ant;

	while (ants)
	{
		ant = ants->content;
		if(!ant->end)
			return (0);
		ants = ants->next;
	}
	return (1);
}

void		refresh(t_list	**tmp, int *sum, int *prev, t_list **paths)
{
	*tmp = *paths;
	*sum = 0;
	*prev = 0;
}

void		swith_params(int	params, t_list	*map, t_list *paths)
{
	if (!paths)
		put_err_msg_exit("There is no paths for this map");
	if (params != 2)
		print_map(map);
	if (params == 3)
		print_paths(paths);
}

void		print_map(t_list *map)
{
	ft_printf("\n");
	while (map)
	{
		ft_printf("%s\n", map->content);
		map = map->next;
	}
	ft_printf("\n");
}

int			print_paths(t_list	*tmp_paths)
{
	t_list	*link;
	t_room	*room;
	int		number;

	number = 1;
	ft_printf("%.10sPATHS FOR ALL ANTS\n%s", RED, RESET);
	while (tmp_paths)
	{
		ft_printf("%s%d path\n%s", GRN, number++, RESET);
		link = tmp_paths->content;
		while (link)
		{
			room = link->content;
			ft_printf("%s%s %s", CYN, room->name, RESET);
			link = link->next;
		}
		ft_printf("\n");
		tmp_paths = tmp_paths->next;
	}
	return (0);
}