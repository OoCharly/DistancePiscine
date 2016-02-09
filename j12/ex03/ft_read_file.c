/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:16:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/09 17:12:49 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

int		i_am_not_legion(char *buff)
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

int		we_are_legion(char *buff, int *ct, int fd)
{
	int		n;
	char	a;
	int		i;

	if (i_am_not_legion(buff))
		return (read(fd, buff, 16));
	n = read(fd, buff, 16);
	if (n != 16 || !i_am_legion(buff, a))
		return (n);
	write(1, "*\n", 2);
	while (n == 16 && i_am_legion(buff, a))
	{
		*ct += n;
		n = read(fd, buff, 16);
	}
	return (n);
}

int		ft_create_buffer(int *fd, int *i, char **av, char *buff)
{
	int	n;

	n = read(*fd, buff, 16)
	while (n != 16)
	{
		if (close(*fd) < 0)
			return(ft_puterr(av[i]));
		if (ft_next_fd(int *fd, &i, **av) < 0)
			return (n);
		else
			n += read(fd, &buff[n], 16 - n);
	}
	return (n);
}

int		*ft_read_hexdump(int *fd, char *buff, int *ct)
{
}
