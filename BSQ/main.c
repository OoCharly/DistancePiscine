/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:50:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/23 14:30:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int		ft_open(char *fn)
{
	int		fd;

	fd = open(fn);
	if (fd < 0)
	{
		write(1, "map error\n", 10);
		return (fd);
	}
	else
		return (fd);
}

int		ft_copy_stdin(void)
{
	int		n;
	int		fd;
	char	buff[BUFF_SIZE];

	fd = open("./temp/cpy_stdin", O_CREAT | O_RDWR | O_TRUNC , MY_MODE);
	if (fd < 0)
		return (0);
	n = read(0, buff, BUFF_SIZE);
	write (fd, buff, n);
	while (n == BUFF_SIZE)
	{
		n = read(0, buff, BUFF_SIZE);
		write(fd, buff, BUFF_SIZE);
	}
	if (close(fd) < 0)
		return (0);
	return (1);
}

void	do_magic(char *fn)
{
	int		i;
	int		fd;
	
	fd = ft_open(fn);
	if (fd < 0)
		return (0);
	i = 1;
	if (!ft_get_info_map(fd))
	{
		write(1, "map error\n", 10);
		return (0);
	}
	if (close(fd) < 0)
		return (0);
	fd = ft_open(fn);
	ft_find_bsq(fd);
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	
	i = 1;
	if (ac == 1)
	{
		ft_copy_stdin();
		do_magic("./temp/cpy_stdin");
	}
	while (i < ac)
	{
			do_magic(av[i]);
			i++;
	}
	return (0);
}
