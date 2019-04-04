/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:43:03 by acolas            #+#    #+#             */
/*   Updated: 2019/04/04 16:05:48 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list		*algorithm(t_list **rooms)
{
	t_list	*path;
	t_list	*tmp_paths;
	t_list	*solution;

	solution = NULL;
	while ((path = bfs(rooms)))
	{
		tmp_paths = path;
		solution = add_to_the_end_of_list(solution, tmp_paths);
		clear_rooms(rooms, solution);
	}
}

t_list		*give_start_room(t_list	**rooms)
{
	t_list	*crawler;
	t_room	*room;
	t_list	*new;

	crawler = rooms;
	while (crawler)
	{
		room = (t_room *)crawler->content;
		if (room->is_start)
		{
			new = ft_lstnew(NULL, 0);
			new->content = crawler->content;
			return (new);
		}
		crawler = crawler->next;
	}
	return (NULL);
}

int			contains(t_list *path, t_room *node)
{
	t_room	*room;
	t_list	*crawler;
	
	while (path)
	{
		crawler = path->content;
		while (crawler)
		{
			room = crawler->content;
			if (room == node)
				return (1);
			crawler = crawler->next;
		}
		path = path->next;
	}
	return (0);
}

void		clear_rooms(t_list **rooms, t_list *path)
{
	t_list	*crawler;
	t_room	*room;

	crawler = *rooms;
	while (crawler)
	{
		room = crawler->content;
		if (!room->is_start && !room->is_end &&contains(path, room))
			room->is_closed = 1;
		else
			room->is_closed = 0;
		room->is_visited = 0;
		crawler = crawler->next;
	}
}

t_list		*bfs(t_list **rooms)
{
	t_list	*queue;
	t_room	*node;
	t_list	*new_paths;
	t_list	*to_free;

	queue = give_start_room(rooms);
	new_paths = NULL;
	while (queue)
	{
		node = (t_room *)queue->content;
		to_free = queue;
		queue = queue->next;
		free(to_free);
		add_to_queue(&queue, node, &new_paths);
		if (new_paths)
		{
			free_queue(&queue);
			break;
		}
	}
	return (new_paths);
}