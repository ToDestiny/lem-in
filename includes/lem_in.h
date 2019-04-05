/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:46:52 by acolas            #+#    #+#             */
/*   Updated: 2019/04/05 11:46:48 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# define ERROR_ROOMS "Error: Invalid map (more than one start/end, etc..)"
# define MAG "\x1B[35m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define CYN "\x1B[36m"
# define RESET "\x1B[0m"

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
}					t_link;

typedef	struct 		s_ant
{
		int				ant;
		int				end;
		t_list			*path;
}					t_ant;

typedef struct 		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}					t_coord;

int				ft_printf(const char *fm, ...);
int				get_next_line(const int fd, char **line);
t_list			*add_to_the_end_of_list(t_list *head, t_list *new);
int				parse_params(char **av);
void			validate(t_list *map, int params);
void			check_rooms(t_list *rooms, t_room *to_find);
void			*validate_room(char *str, t_list *head, int start_end);
void			set_links(t_room **room_one, t_room **room_two);
void			validate_link(char *str, t_list **rooms_add);
t_room			*create_room(char *name, int x, int y, int start_end);
t_list			*create_ants(int num_of_ants);
void			add_rooms_and_links(t_list *map, t_list **rooms);
void			parsing_map_info(char *map_content, int *commands_num, t_list **rooms, int *start_end);
t_list			*last_elem(t_list *head);
void			save_path(t_room *node, t_list **paths);
void			free_queue(t_list **queue);
void			add_to_queue(t_list **queue, t_room *node, t_list **paths);
void			make_move(t_ant **ant);
t_list			*give_path(t_list *paths, int sum, int on_start, int prev);
int				all_with_paths(t_list **ants);
int				move(t_list *ants, t_list *paths, int num_of_ants);
void			give_paths(t_list **ants, t_list *paths, int on_start);
t_list			*algorithm(t_list **rooms);
t_list			*give_start_room(t_list	**rooms);
int				contains(t_list *path, t_room *node);
void			clear_rooms(t_list **rooms, t_list *path);
t_list			*bfs(t_list **rooms);
int				list_count(t_list *list);
int				spec_atoi(const char *str);
void			check_for_add_sym(char *str);
int				count_size(char **arr);
void			free_str_arr(char **arr, int size);
void			put_err_msg_exit(char *str);
int				str_arr_count(char **arr);
void			is_sorted(t_stack *stack);
void			free_list(t_stack **stack);
int				all_at_end(t_list *ants);
void			refresh(t_list	**tmp, int *sum, int *prev, t_list **paths);
void			switch_params(int	params, t_list	*map, t_list *paths);
void			print_map(t_list *map);
int				print_paths(t_list	*tmp_paths);

#endif
