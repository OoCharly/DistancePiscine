/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:45:00 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/23 15:15:45 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	ft_show_rainbow(int fd)
{
	int		up_left;
	int		n;
	char	buff[BUFF_SIZE];
	int		i;

	up_left = (g_bsq.y - 1) * (g_map.len + 1) + g_bsq.x - 1;
	while (up_left > BUFF_SIZE)
	{
		read(fd, buff, BUFF_SIZE);
		write(1, buff, BUFF_SIZE);
		up_left -= BUFF_SIZE;

	}
	n = read(fd, buff, BUFF_SIZE);
	write(1, buff, (n - up_left));
	i = 0;
	while (i < g_bsq.len)
	{
		write(1, &g_map.plein, 1);
		i++;
	}
	up_left += g_map.len - g_bsq.len + 1;

