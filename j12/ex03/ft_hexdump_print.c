/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:15:51 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/03 14:20:44 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

void	ft_print_offset(int ct)
{
	char	nbr[7];
	int		i;

	i = 0;
	nbr[0] = ft_dec_to_hex(ct / 16777216);
	nbr[1] = ft_dec_to_hex((ct / 1048576) % 16);
	nbr[2] = ft_dec_to_hex((ct / 65536) % 16);
	nbr[3] = ft_dec_to_hex((ct / 4096) % 16);
	nbr[4] = ft_dec_to_hex((ct / 256) % 16);
	nbr[5] = ft_dec_to_hex((ct / 16) % 16);
	nbr[6] = ft_dec_to_hex(ct % 16);
	while (i < 7)
		write(1, &nbr[i++], 1);
}

void	ft_print_hexdump(char *buff,int n)
{
	int	i;
	int	j;

	i = 0;
	j = n % 2;
	while(i < (n - j))
	{
		write(1, " ", 1);
		ft_char_to_hex(buff[i + 1]);
		ft_char_to_hex(buff[i]);
		i += 2;
	}
	if (j)
	{
		write(1, " 00", 1);
		ft_char_to_hex(buff[i]);
		i += 2;
	}
	while (i < 16)
	{
		write(1, "     ", 5);
		i += 2;
	}
	write(1, "\n", 1);
}

void	ft_print_hexdump_C(char *buff, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		ft_char_to_hex(buff[i]);
		if (!(i % 8)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "   ", 3);
		i++:
	}
	i = 0;
	write(1, "  |", 3);
	while (i < n)
	{
		if(buff[i] > 31 && buff[i] < 127)
			write(1, &buff[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|\n", 2);
}

void	ft_print(char *buff, int opt, int n, int ct)
{
	ft_print_offset(ct);
	if (opt)
		ft_print_hexdump_C(buff, n);
	else
		ft_print_hexdump(buff, n);
}