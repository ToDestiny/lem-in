/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:46:52 by acolas            #+#    #+#             */
/*   Updated: 2019/03/28 14:36:24 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# define ERROR_ROOMS "Error: Invalid map (more than one start/end, etc..)"

typedef struct 		s_room
{
		char			*name;
		int				is_start;
		int				is_end;
		struct s_room	*from;
		t_list			*links;
		int				x;
		int				y;
		int				is_visited;
		int				is_closed;
		int				ant;
}					t_room;

typedef	struct 		s_link
{
		t_room			*r1;
		t_room			*r2;
};					t_link;

typedef	struct 		s_ant
{
		int				ant;
		int				end;
		t_list			*path;
};					t_ant;


int				ft_printf(const char *fm, ...);
t_list			*add_to_the_end_of_list(t_list *head, t_list *new);
int				parse_params(char **av);


#endif