/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:43:49 by acolas            #+#    #+#             */
/*   Updated: 2019/04/19 14:13:10 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H

# define FLAGS "qprRes"

typedef enum e_option	t_option;

enum	e_option
{
	quiet_mode = 1 << 0,
	show_paths = 1 << 1,
	show_rooms = 1 << 2,
	show_all_rooms = 1 << 3,
	error_management = 1 << 4,
	show_statistic = 1 << 5,
};

void	lem_options();

#endif
