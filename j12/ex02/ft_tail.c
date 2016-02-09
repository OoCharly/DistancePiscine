/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:02:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 16:24:59 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_02.h"

int	ft_fsize(char *fn)
{
	int		fd;
	int		size;
	int		n;
	char	buff;

	size = 0;
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (ft_puterr(fn, errno));
	n = read(fd, &buff, 1);
	while (n)
	{
		n = read(fd, &buff, 1);
		size++;
	}
	if (close(fd) < 0)
		return (ft_puterr(fn, errno));
	return (size);
}

int	ft_tail(char *fn, int offset)
{
	int		fd;
	int		n;
	char	*buff;
	int		ofs;

	ofs = offset;
	if (offset == 0)
		ofs = 4000;
	if (!(buff = malloc(sizeof(*buff) * ofs)))
		return (ft_puterr(fn, errno));
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (ft_puterr(fn, errno));
	n = read(fd, buff, ofs);
	if (offset == 0)
		write(1, buff, n);
	while (n)
	{
		n = read(fd, buff, ofs);
		write(1, buff, n);
	}
	if (close(fd) < 0)
		return (ft_puterr(fn, errno));
	free(buff);
	return (0);
}

int	ft_get_offset_pos(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-c") && av[i + 1])
			return (i + 1);
		i++;
	}
	return (-1);
}

int	ft_offset(char **av, int opt, int size)
{
	int	tmp;

	tmp = ft_atoi(av[opt]);
	if (tmp > size)
		return (size);
	if (-tmp > size)
		return (0);
	else
		return ((size + tmp) % size);
}

int	main(int ac, char **av)
{
	int		i;
	int		out;
	int		opt;

	i = 1;
	out = 0;
	if (ac <= 3)
		return (1);
	opt = ft_get_offset_pos(av);
	if (opt < 0)
		return (1);
	out = ft_compress(ac, av, opt);
	return (out);
}
