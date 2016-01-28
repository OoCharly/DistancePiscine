/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:00:34 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 11:13:18 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

int	ft_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_puterr(filename, errno);
		return (fd);
	}
	else
		return (fd);
}

void	ft_putstr(char *str, int out)
{
	while (*str)
	{
		write(out, str, 1);
		str++;
	}
}

int		ft_puterr(char *fn, int er)
{
	if (er == ENOMEM)
		return (-1);
	ft_putstr("hexdump", 7);
	ft_putstr(": ", 2);
	ft_putstr(fn, 2);
	ft_putstr(": ", 2);
	if (er == EACCES)
		ft_putstr("Permission denied\n", 2);
	if (er == ENOENT)
		ft_putstr("No such file or directory\n", 2);
	return (-1);
}
