/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:40:54 by acolas            #+#    #+#             */
/*   Updated: 2019/04/04 15:53:22 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_str_arr(char **arr, int size)
{
	int		ind;

	ind = 0;
	while (ind < size)
		ft_strdel(&arr[ind++]);
	free(arr);
	arr = NULL;
}

int			count_size(char **arr)
{
	char		**tmp;
	int			size;

	size = 0;
	tmp = arr;
	while (tmp[size])
		size++;
	return (size);
}

void		check_for_add_sym(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
		!ft_isdigit(*tmp) ?
			(put_err_msg_exit("Error: Found non-integer symbol where should be integer only."))
			: tmp++;
}

int			spec_atoi(const char *str)
{
	char				*tmp;
	unsigned long int	num;

	num = 0;
	tmp = (char *)str;
	check_for_add_sym(tmp);
	while (*tmp > 47 && *tmp < 58)
	{
		num = (*tmp- 48) + (num * 10);
		if (num > 2147483647)
			put_err_msg_exit("Error: number more than int-max value.");
		tmp++;
	}
	return ((int)(num));
}

int			list_count(t_list *list)
{
	int		count;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}