/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:16:52 by acolas            #+#    #+#             */
/*   Updated: 2019/04/10 18:16:54 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "libft.h"

typedef struct	s_array
{
	void	**ptr;
	size_t	len;
	size_t	max;
}				t_array;

#endif