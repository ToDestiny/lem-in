/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:16:42 by acolas            #+#    #+#             */
/*   Updated: 2019/04/05 17:11:04 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/lem_in.h"

void		put_err_msg_exit(char *str)
{
	ft_printf("%s", MAG);
	ft_putendl_fd(str, 2);
	exit(0);
}

int			str_arr_count(char **arr)
{
	int		count;

	count = 0;
	while (arr[++count])
		;
	return (count + 1);
}

void		is_sorted(t_stack *stack)
{
	t_stack		*crawler;

	crawler = stack;
	while (crawler && crawler->next)
	{
		if (crawler->data > crawler->next->data)
		{
			ft_putendl("KO");
			return ;
		}
		crawler = crawler->next;
	}
	ft_putendl("OK");
}

void		free_list(t_stack **stack)
{
	t_stack		*tmp;
	t_stack		*crawler;

	crawler = *stack;
	while (crawler)
	{
		tmp = crawler->next;
		free(crawler);
		crawler = tmp;
	}
	*stack = NULL;
}