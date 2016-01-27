/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 13:45:47 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/05 17:51:59 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_display(char *file)
{
	char	tab[4096];
	int		fd;
	int		n;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "open() failed", 13);
		return (0);
	}
	n = read(fd, tab, 4096);
	while (n)
	{
		write(1, tab, n);
		n = read(fd, tab, 4096);
	}
	if (close(fd) < 0)
	{
		write(2, "close() failed", 13);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		write(2, "File name missing.", 18);
		return (1);
	}
	if (ac > 2)
	{
		write(2, "Too many arguments.", 19);
		return (1);
	}
	if (ft_display(av[1]))
		return (0);
	else
		return (1);
}
