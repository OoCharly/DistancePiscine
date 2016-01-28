/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:51:20 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/27 22:30:08 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

void	ft_print_offset(int ct)
{
	char	nbr[7];
	int		i;

	i = 0;
	nbr[0] = ft_itoh(ct / 16777216);
	nbr[1] = ft_itoh((ct / 1048576) % 16);
	nbr[2] = ft_itoh((ct / 65536) % 16);
	nbr[3] = ft_itoh((ct / 4096) % 16);
	nbr[4] = ft_itoh((ct / 256) % 16);
	nbr[5] = ft_itoh((ct / 16) % 16);
	nbr[6] = ft_itoh(ct % 16);
	while (i < 7)
		write(1, &nbr[i++], 1);
}

void	i_am_not_printable(char c)
{
	if (c != 0 && !(c > 6 && c < 14))
		ctooct(c);
	else
	{
		if (c == 0)
			write(1, " \\0", 3);
		if (c == 7)
			write(1, " \\a", 3);
		if (c == 8)
			write(1, " \\b", 3);
		if (c == 9)
			write(1, " \\t", 3);
		if (c == 10)
			write(1, " \\n", 3);
		if (c == 11)
			write(1, " \\v", 3);
		if (c == 12)
			write(1, " \\f", 3);
		if (c == 13)
			write(1, " \\r", 3);
	}
}

void	ft_print_line(char *buff, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write(1, " ", 1);
		if (buff[i] > 31 && buff[i] < 127)
		{
			write(1, "  ", 2);
			write(1, &buff[i], 1);
		}
		else
			i_am_not_printable(buff[i]);
		i++;
	}
	while (i < 16)
	{
		write(1, "    ", 3);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_hex_line(char *buff, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write(1, " ", 1);
		if (buff[i + 1])
			ft_put_hex_char(buff[i + 1]);
		else
			write(1, "00",2);
		ft_hex_to_car(buff[i]);
		i += 2;
	}
	while (i < 16)
	{
		write(1, "    ", 3);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_hex(int ct, int n, char *buff, int opt)
{
	ft_print_offset(ct);
	if (opt)
		ft_print_line(buff, n);
	else
		ft_print_hex_line(buff, n);
}
