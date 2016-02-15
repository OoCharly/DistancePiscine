/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 16:31:54 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/04 16:44:47 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		i_am_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cpy_my_word(char *ult_tab_tab, char *str, int i, int w)
{
	int j;

	ult_tab_tab = malloc(sizeof(*ult_tab_tab) * (w + 1));
	j = 0;
	while (j < w)
	{
		ult_tab_tab[j] = str[i];
		i++;
		j++;
	}
	ult_tab_tab[w] = '\0';
	return (ult_tab_tab);
}

int		ft_put_my_strings(char **ult_tab, char *str, char *charset)
{
	int i;
	int j;
	int w;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (i_am_charset(str[i], charset) && str[i])
			i++;
		if (!str[i])
			break ;
		w = 0;
		while (!(i_am_charset((str[i]), charset) && str[i]))
		{
			i++;
			w++;
		}
		ult_tab[j] = ft_cpy_my_word(ult_tab[j], str, i - w, w);
		j++;
	}
	ult_tab[j] = 0;
	return (1);
}

int		ft_count_my_string(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (i_am_charset(str[i], charset) && str[i])
		{
			i++;
		}
		if (!str[i])
		{
			return (j);
		}
		while (!(i_am_charset(str[i], charset) && str[i]))
			i++;
		j++;
	}
	return (j);
}

char	**ft_split(char *str, char *charset)
{
	char	**ult_tab;

	if (!(ult_tab = malloc(sizeof(*ult_tab) *
	(ft_count_my_string(str, charset) + 1))))
		return ((char **)NULL);
	ft_put_my_strings(ult_tab, str, charset);
	return (ult_tab);
}
