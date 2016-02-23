/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:18:58 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/23 19:12:36 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	ft_first_line(int fd)
{
	char		i;

	i = 'a';
	while (i != '\n')
		read(fd, &i, 1);
}

void	ft_larger_bsq(int *line, int floor)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < g_map.len)
	{
		if ((floor == g_bsq.len) ||
		((n + g_map.len - i) < (g_bsq.len + 1)) ||
		(g_bsq.len == g_map.len))
			break ;
		if (line[i] > g_bsq.len)
			n++;
		else
			n = 0;
		i++;
		if (n == (g_bsq.len + 1))
		{
			g_bsq.x = i - n + 1;
			g_bsq.y = floor - n + 1;
			g_bsq.len++;
			i = 0;
			n = 0;
		}
	}
}

void	ft_get_negative(int fd, int *neg)
{
	int		i;
	char	a;

	i = 0;
	while (i < g_map.len)
	{
		read(fd, &a, 1);
		if (a == g_map.vide)
			neg[i] = 1;
		else
			neg[i] = 0;
		i++;
	}
	read(fd, &a, 1);
}

void	ft_calc_floor(int *neg, int *line)
{
	int		i;

	i = 0;
	while (i < g_map.len)
	{
		line[i] = (line[i] + 1) * neg[i];
		i++;
	}
}

void	ft_find_bsq(int fd)
{
	int		*neg;
	int		*line;
	int		n;

	ft_first_line(fd);
	if (!ft_create_init_tabs(&neg, &line))
		return ;
	n = 1;
	while ((n <= g_map.n_ligne) && (g_map.len != g_bsq.len))
	{
		ft_get_negative(fd, neg);
		ft_calc_floor(neg, line);
		ft_larger_bsq(line, n);
		n++;
	}
	free(neg);
	free(line);
}
