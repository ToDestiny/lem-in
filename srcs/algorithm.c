/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:43:03 by acolas            #+#    #+#             */
/*   Updated: 2019/04/03 18:14:07 by acolas           ###   ########.fr       */
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