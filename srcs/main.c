/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:49:55 by acolas            #+#    #+#             */
/*   Updated: 2019/03/27 22:07:30 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_params(char **argv)
{
	if (!argv[1])
		return (0);
	if (!ft_strcmp(argv[1], "--leaks"))
		return (1);
	else if (!ft_strcmp(argv[1], "--silent"))
		return (2);
	else if (!ft_strcmp(argv[1], "--paths"))
		return (3);
	else if (!ft_strcmp(argv[1], "--moves"))
		return (4);
	else
		return (0);
}

t_list	*add_to_the_end_of_list(t_list *head, t_list *new)
{
	t_list	*crawler;

	crawler = head;
	if (!crawler)
		return (new);
	while (crawler = crawler->next)
		crawler = crawler->next;
	crawler->next = new;
	return (head);
}

int		main(int ac, char **av)
{
	char	*line;
	t_list	*map;
	t_list	*new;
	int		params;

	while (get_next_line(0, &line) > 0)
	{
		new = ft_lstnew(NULL, 0);
		new->content = line;
		map = add_to_the_end_of_list(map, new);
	}
	argc ? (params = parse_params(argv)) :
		(params = 0);
	if (!map)
		put_err_msg_exit("Usage: You need to give a valid map");
	validate(map, params);
	if (params == 1)
		system("leaks lem-in");
}
