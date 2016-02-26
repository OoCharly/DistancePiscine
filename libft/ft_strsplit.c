/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:43:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 10:42:03 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(char const *s, char c)
{
	int		w;

	w = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (w);
		w++;
		while (*s != c && *s)
			s++;
	}
	return (w);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**out;
	int		size;
	int		i;

	if (!(out = malloc(sizeof(char*) * ft_nwords(s, c))))
		return (NULL);
	if (!out)
		return (NULL);
	i = 0;
	size = 0;
	while (*out)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (out);
		while (s[size] != c && s[size])
			size++;
		out[i] = ft_strncpy(ft_strnew(size), s, size);
		s += size;
		if (!out[i])
			return (NULL);
		i++;
	}
	return (out);
}
