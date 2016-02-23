/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:11:19 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/23 13:12:00 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int		ft_parse_param_map(char *first_line)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		n *= 10;
		n += (str[i] - 48);
	}
	g_map.n_ligne = n;
	if (!i)
		return (0);
	g_map.vide = first_line[i++];
	g_map.obstacle = first_line[i++];
	g_map.plein = first_line[i++];
	if (first_line[i] != '\n')
		return (0);
	return (1);
}

int		ft_get_info_map(int fd)
{
	char	first_line[100];
	int		i;
	int		n;
	char	buff;

	i = 0;
	n = 1;
	while (n)
	{
		read(fd, &buff, 1);
		first_line[i++] = buff;
		if (buff == '\n')
			break ;
	}
	if (i < 4)
		return (0);
	if (!ft_parse_param_map(first_line))
		return (0);
	return (1);
}

int		ft_get_line_len(int fd)
{
	int		i;
	char	a;

	i = 0;
	n = read(fd, &a, 1);
	while (a != '\n' && n != 0)
		i++;
	if (a != '\n')
		return (0);
	return (i);
}

char	*ft_get_line(int fd, char *buff)
{
	char	*line;

	
