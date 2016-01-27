/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:02:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/27 18:45:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_02.h"

int	ft_fsize(char *fn, char *ft)
{
	int		fd;
	int		size;
	int		n;
	char	buff;

	size = 0;
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (ft_puterr(ft, fn, errno));
	n = read(fd, &buff, 1);
	while (n)
	{
		n = read(fd, &buff, 1);
		size++;
	}
	if (close(fd) < 0)
		return (ft_puterr(ft, fn, errno));
	return (size);
}

int	ft_tail(char *fn, char *ft, int offset)
{
	int		fd;
	int		n;
	char	*buff;

	if (!(buff = malloc(sizeof(*buff) * offset)))
		return (ft_puterr(ft, fn, errno));
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (ft_puterr(ft, fn, errno));
	n = read(fd, buff, offset);
	while (n)
	{
		n = read(fd, buff, offset);
		write(1, buff, n);
	}
	if (close(fd) < 0)
		return (ft_puterr(ft, fn, errno));
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
	int		tab[3];

	i = 1;
	tab[0] = 0;
	if (ac <= 1)
		return (tab[0]);
	tab[1] = ft_get_offset_pos(av);
	if (tab[1] < 0)
		return (1);
	while (av[i])
	{
		if (i != tab[1] && i != (tab[1] - 1))
		{
			if (ft_fsize(av[i], av[0]) > 0)
			{
				tab[2] = ft_offset(av, tab[1], ft_fsize(av[i], av[0]));
				ft_tail(av[i], av[0], tab[2]);
			}
			else
				tab[0] = 1;
		}
		i++;
	}
	return (tab[0]);
}
