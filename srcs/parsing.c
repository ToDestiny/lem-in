/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:31:20 by acolas            #+#    #+#             */
/*   Updated: 2019/04/05 11:30:43 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parsing_map_info(char *map_content, int *commands_num, t_list **rooms, int *start_end)
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
		parsing_map_info(map->content, &commands_num, rooms, &start_end);
		map = map->next;
	}
}

t_list	*create_ants(int num_of_ants)
{
	t_list	*head;
	t_ant	*ant;
	t_list	*new;

	head = NULL;
	while (num_of_ants)
	{
		ant = (t_ant *)malloc(sizeof(t_ant));
		ant->ant = num_of_ants;
		ant->path = NULL;
		ant->end = 0;
		new = ft_lstnew(NULL, 0);
		new->content = ant;
		ft_lstadd(&head, new);
		num_of_ants--;
	}
	return (head);
}

t_room	*create_room(char *name, int x, int y, int start_end)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	room->x = x;
	room->y = y;
	room->name = ft_strdup(name);
	room->is_start = (start_end == 1 ? 1 : 0);
	room->is_end = (start_end == 2 ? 1 : 0);
	room->from = NULL;
	room->is_visited = 0;
	room->is_closed = 0;
	room->ant = 0;
	return (room);
}