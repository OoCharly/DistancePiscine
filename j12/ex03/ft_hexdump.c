/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:40:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 00:19:23 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

int	i_am_legion(char *str, char *a)
{
	int		i;
	char	tmp;

	if (*a >= 0)
		tmp = *a;
	else
	{
		tmp = str[0];
		*a = str[0];
	}
	i = 0;
	while (i < 16)
	{
		if (str[i] != tmp)
		{
			*a = -1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	we_are_legion(char *buff, char *a, int fd, int *ct)
{
	int	out;

	out = read(fd, buff, 16);
	if (!i_am_legion(buff, a) || ((out % 16) != 0))
	{
		*ct += out;
		return (out);
	}
	write(1, "*\n", 2);
	while (!(out % 16))
	{
		if (i_am_legion(buff, a) && out == 16)
		{
			*ct += 16;
			out = read(fd, buff, 16);
		}
		else
		{
			*ct += out;
			return (out);
		}
	}
	return (out);
}

int	test(int *ct, char *buff, int fd, int n)
{
	char	a;

	a = -1;
	ft_print_hex(*ct, n, buff);
	if (i_am_legion(buff, &a))
		n = we_are_legion(buff, &a, fd, ct);
	else
	{
		n = read(fd, buff, 16);
		*ct += 16;
	}
	return (n);
}

int	ft_read_file(char *fn, int opt)
{
	int		ct;
	int		fd;
	int		n;
	char	buff[16];

	ct = 0;
	n = read(fd, &buff, 16);
	while (n == 16)
	{
		ft_print_hex(*ct, n, buff, opt);
		n = test(&ct, buff, fd, n);
	}
	if (n)
	{
		ft_print_hex(ct, n, buff);
		ct += n;
	}
	ft_print_offset(ct);
	write(1, "\n", 1);
	return (0);
}
