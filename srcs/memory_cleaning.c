/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:56:53 by acolas            #+#    #+#             */
/*   Updated: 2019/04/05 12:08:11 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_paths(t_list **paths)
{
	t_list	*links;
	t_list	*to_free;
	t_list	*to_free2;

	while (*paths)
	{
		links = (*paths)->content;
		while (links)
		{
			to_free = links;
			links = links->next;
			free(to_free);
		}
		to_free2 = *paths;
		*paths = (*paths)->next;
		free(to_free2);
	}
	free(*paths);
}

void		free_rooms(t_list **rooms)
{
	t_room	*room;
	t_list	*links;
	t_list	*to_free;

	while (*rooms)
	{
		room = (*rooms)->content;
		free(room->name);
		links = room->links;
		while (links)
		{
			to_free = links;
			links = links->next;
			free(to_free);
		}
		to_free = *rooms;
		*rooms = (*rooms)->next;
		free(to_free);
		free(room);
	}
	free(*rooms);
}

void		clean(t_list **rooms, t_list **ants, t_list **paths)
{
	t_list	*to_free;

	free_rooms(rooms);
	free_paths(paths);
	while (*ants)
	{
		to_free = *ants;
		free(to_free->content);
		*ants = (*ants)->next;
		free(to_free);
	}
	free(*ants);
}