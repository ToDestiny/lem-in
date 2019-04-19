/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assoc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:28:11 by acolas            #+#    #+#             */
/*   Updated: 2019/04/19 14:13:27 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASSOC_H
# define FT_ASSOC_H

typedef struct	s_assoc
{
	char	**key;
	void	**ptr;
	int		len;
	int		max;
}				t_assoc;

#endif
