/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:11:19 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/23 19:45:57 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int		ft_get_line_len(int fd)
{
	int		i;
	char	a;
	int		n;

	i = 0;
	n = read(fd, &a, 1);
	while (a != '\n' && n != 0)
	{
		n = read(fd, &a, 1);
		if (a != '\n' && a != g_map.vide && a != g_map.obstacle)
			return (0);
		i++;
	}
	if (a != '\n')
		return (0);
	return (i);
}

int		ft_atoi(char *str, int j)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while(i <= j)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		n += str[i] - 48;
		n *= 10;
		i++;
	}
	return (n / 10);
}

int		ft_parse_param_map(char *str, int i, int fd)
{
	int		j;

	j = i - 1;
	g_map.plein = str[j--];
	g_map.obstacle = str[j--];
	g_map.vide = str[j--];
	g_map.n_ligne = ft_atoi(str, j);
	if (!g_map.n_ligne)
		return (0);
	g_map.len = ft_get_line_len(fd);
	if (!g_map.len)
		return (0);
	return (1);
}

int		ft_test_map_line(fd)
{
	int		i;
	char	a;

	i = 1;
	while (i < g_map.n_ligne)
	{
		if (ft_get_line_len(fd) != g_map.len)
			return (0);
		i++;
	}
	i = read(fd, &a, 1);
	if (i != 0)
		return (0);
	return (1);
}

int		ft_get_info_map(int fd)
{
	char	first_line[BUFF_SIZE];
	int		i;
	int		n;
	char	buff;

	i = 0;
	n = 1;
	while (n)
	{
		n = read(fd, &buff, 1);
		first_line[i] = buff;
		if (buff == '\n')
			break ;
		i++;
	}
	if (i < 4)
		return (0);
	if (!ft_parse_param_map(first_line, i, fd))
		return (0);
	if (!ft_test_map_line(fd))
		return (0);
	return (1);
}

