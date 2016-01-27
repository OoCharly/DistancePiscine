/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 14:58:08 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/06 09:27:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12.h"

void		ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void		ft_putstr(char *str, int out)
{
	while(*str)
	{
		ft_putchar(*str, out);
		str++;
	}
}

int		ft_display_file(char *file)
{
	char	tab[30000];
	int		fd;
	int		n;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		return (errno);
	}
	n = read(fd, tab, 30000);
	while (n)
	{
		write(1, tab, n);
		n = read(fd, tab, 30000);
	}
	if (close(fd) < 0)
	{
		return (errno);
	}
	return (0);
}

int		ft_puterr(char *ft, char *fn, int er)
{
	if(er)
	{
		ft_putstr(ft,2);
		ft_putstr(": ",2);
		ft_putstr(fn,2);
		ft_putstr(": ",2);
		if (er == EACCES)
			ft_putstr("Permission denied\n",2);
		if (er == ENOENT)
			ft_putstr("No such file or directory\n",2);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	i;
	int	out;

	i = 1;
	out = 0;
	if (ac == 1)
	{
		return (out);
	}
	if (ac > 1)
	{
		while (i < ac)
		{
			if(ft_puterr(av[0], av[i], ft_display_file(av[i])))
				out = 1;
			i++;
		}
	}
	return (out);
}
