/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:17:01 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/15 17:10:25 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int		ft_check_line(int fd)
{
	int		i;
	int		n;
	char	a;

	i = 0;
	n = read(fd, &a, 1);
	while (n)
	{
		i++;
		if (a != g_map.vide && a != g_map.obstacle)
			return (0);
		if (a == '\n')
			break ;
	}
	if (a != '\n')
		return (0);
	return (i);
}

int		ft_check_map(int fd)
{
	int		i;
	int		n;
	int		len

	i = 1;
	n = ft_check_line(fd);
	if (!n)
		return (0);
	len = n;
	while (i < g_map.n_line)
	{
		n = ft_check_line(fd);
		if (n != len)
			return (0);
		i++;
	}
	n = ft_check_line(fd);
	if (n)
		return (0);
	return (1);
}

int		ft_create_init_tabs(int **neg, int **line)
{
	int		i;

	if (!(*neg = malloc(sizeof(int) * g_map.len)))
		return (0);
	if (!(*line = malloc(sizeof(int) * g_map.len)))
		return (0);
	i = 0;
	while (i < g_map.len)
	{
		(*neg)[i] = 0;
		(*line)[i] = 0;
		i++;
	}
	return (1)
}
