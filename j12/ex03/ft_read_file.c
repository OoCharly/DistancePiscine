/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:16:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/09 19:28:30 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

int		am_i_legion(char *buff)
{
	int	i;

	i = 1;
	while ((buff[0] == buff[i]) && (i < 16))
		i++;
	return (i % 16);
}

int		i_am_legion(char *buff, char a)
{
	int	i;

	i = 0;
	while ((buff[i] == a) && (i < 16))
		i++;
	if (i != 16)
		return (0);
	return (1);
}

int		we_are_legion(int *fd, int *i, char **av, char *buff)
{
	int		n;
	char	a;

	if (!am_i_legion(buff))
		return (ft_create_buffer(fd, i, av, buff));
	a = buff[0];
	n = ft_create_buffer(fd, i, av, buff);
	if (n != 16 || !i_am_legion(buff, a))
		return (n);
	ft_print(buff, n);
	write(1, "*\n", 2);
	while (n == 16 && i_am_legion(buff, a))
	{
		g_offset += n;
		n = ft_create_buffer(fd, i, av, buff);
	}
	return (n);
}

int		ft_create_buffer(int *fd, int *i, char **av, char *buff)
{
	int	n;

	n = read(*fd, buff, 16);
	while (n != 16)
	{
		printf("/n ici n=%d et fd=%d", n, *fd);
		if (close(*fd) < 0)
			return(ft_puterr(av[*i], errno));
		if (ft_next_fd(fd, i, **av) < 0)
			return (n);
		else
			n += read(*fd, &buff[n], 16 - n);
	}
	return (n);
}
