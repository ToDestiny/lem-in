/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:31:20 by acolas            #+#    #+#             */
/*   Updated: 2019/04/02 12:45:23 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parsing_map_info(char **map_content, int *commands_num, t_list **rooms, int *start_end)
{
	if (!ft_strncmp(map_content, "##start", 7) && ++(*commands_num))
		*start_end = 1;
	else if (!ft_strncmp(map_content, "##end", 5) && ++(commands_num))
		*start_end = 2;
	else if (!ft_strncmp(map_content, "##", 2))
		;
	else if (ft_strchr(map_content, '-') && !rooms)
		put_err_msg_exit("Error, You added a link before a room");
	else if (ft_strchr(map_content, '-') && rooms)
		validate_link(map_content, rooms);
	else if (!ft_strncmp(map_content, "#", 1))
		;
	else if (*commands_num > 2)
		put_err_msg_exit("You can pass start/end command only once");
	else
	{
		*rooms = validate_room(map_content, *rooms, *start_end);
		*start_end ? (*start_end = 0) : *start_end;
	}
}

void	add_rooms_and_links(t_list *map, t_list **rooms)
{
	int	start_end;
	int	commands_num;

	start_end = 0;
	commands_num = 0;
	while (map)
	{
		parsing_map_info(map->content, &command_num, rooms, &start_end);
		map = map->next;
	}
}

t_list	*create_ants(int num_of_ants)
{

}