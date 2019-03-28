/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:39:36 by acolas            #+#    #+#             */
/*   Updated: 2019/03/28 15:34:31 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_rooms(t_list *rooms, t_room *to_find)
{
	t_room *room;

	while (rooms)
	{
		room = rooms->content;
		if (!ft_strcmp(room->name, to_find->name))
			put_err_msg_exit("Rooms can't have same names");
	}
}

void	validate(t_list *map, int params)
{
	int		num_of_ants;
	t_list	*ants;
	t_list	*rooms;
	t_list	*paths;
	t_list	*to_print;

	to_print = map;
	if((num_of_ants = spec_atoi(map->content)) <= 0)
		put_err_msg_exit("Error: Incorrect number of ants.");
	map = map->next;
	rooms = NULL;
	add_rooms_and_links(map, &rooms);
	if (list_count(rooms) < 2)
		put_err_msg_exit("You can give start/end command only once.");
	ants = create_ants(num_of_ants);
	if (params == 4)
		ft_printf("%s\nWas made %d moves\n%s", GRN, num_of_ants, RESET);
		clean(&rooms, &ants, &paths);
}