/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:47:54 by acolas            #+#    #+#             */
/*   Updated: 2019/02/13 16:18:04 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!(s[i] == c))
		count++;
	while (s[i] != '\0')
	{
		if (i > 1)
			if ((s[i - 1] == c) && (s[i] != c))
			{
				count++;
				i++;
			}
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**tab;
	int		count;

	if (!s || !c)
		return (NULL);
	i = 0;
	j = 0;
	count = ft_count_word(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (count + 1))) == 0)
		return (NULL);
	tab[count] = NULL;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_strsub(s + i, 0, ft_word_len(s + i, c));
			i = i + ft_word_len(s + i, c);
			j++;
		}
		else
			i++;
	}
	return (tab);
}


void		ft_free_strary(char **strary)
{
	char **tmp;

	tmp = strary;
	if (!strary)
		return ;
	while (*strary)
		free(*strary++);
	free(tmp);
}
