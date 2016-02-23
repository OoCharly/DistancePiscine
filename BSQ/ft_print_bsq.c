/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:45:00 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/23 20:25:01 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"
int		ft_read_n_write(int fd, char *buff, int n)
{
	int		i;

	i = read(fd, buff, n);
	write(1, buff, i);
	return (i);
}

void	ft_print_sq(void)
{
	int		i;

	i = 0;
	while (i++ < g_bsq.len)
		write(1, &g_map.plein, 1);
}

void	ft_show_rainbow(int fd)
{
	int		sq;
	int		n;
	char	buff[BUFF_SIZE];
	int		i;

	ft_first_line(fd);
	sq = (g_bsq.y - 1) * (g_map.len + 1) + g_bsq.x - 1;
	while (sq > BUFF_SIZE)
	{
		ft_read_n_write(fd, buff, BUFF_SIZE);
		sq -= BUFF_SIZE;
	}
	ft_read_n_write(fd, buff, sq);
	i = 0;
	sq = g_map.len - g_bsq.len + 1;
	while (i < g_bsq.len)
	{
		ft_print_sq();
		read(fd, buff, g_bsq.len);
		n = ft_read_n_write(fd, buff, sq);
		i++;
	}
	while (n != 0)
		n = ft_read_n_write(fd, buff, BUFF_SIZE);
}
