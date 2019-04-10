/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:54:22 by acolas            #+#    #+#             */
/*   Updated: 2019/04/10 18:27:09 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESS_H
# define FT_PROCESS_H

# include "libft.h"

# define FT_INIT(o) ft_init(argc, argv, (o))
# define MLC_ERROR 1
# define MLC_EXIT 2

typedef struct	s_process
{
	char		*name;
	char		**argv;
	int			argc;
	uintmax_t	options;
}				t_process;

t_process	g_process;

#endif
