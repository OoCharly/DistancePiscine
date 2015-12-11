/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 14:58:08 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/04 17:14:24 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_display_file(char *file)
{
	char	tab[30716];
	int		fd;
	int		n;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "open() failed", 13);
		return (0);
	}
	n = read(fd, tab, 30716);
	while (n)
	{
		write(1, tab, n);
		n = read(fd, tab, 30716);
	}
	if (close(fd) < 0)
	{
		write(2, "close() failed", 13);
		return (0);
	}
	return (1);
}

void	ft_display_std()

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_display_std();
		return (0);
	}
	if (ac > 1)
	{
		
	}
	if (ft_display(av[1]))
		return (0);
	else
		return (1);
}
