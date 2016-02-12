/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:15:51 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/12 11:37:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

void	ft_print_offset(int ct)
{
	char	nbr[8];
	int		i;

	if (g_option)
		i = 0;
	else
		i = 1;
	nbr[0] = ft_dec_to_hex(ct / 268435456);
	nbr[1] = ft_dec_to_hex((ct / 16777216) % 16);
	nbr[2] = ft_dec_to_hex((ct / 1048576) % 16);
	nbr[3] = ft_dec_to_hex((ct / 65536) % 16);
	nbr[4] = ft_dec_to_hex((ct / 4096) % 16);
	nbr[5] = ft_dec_to_hex((ct / 256) % 16);
	nbr[6] = ft_dec_to_hex((ct / 16) % 16);
	nbr[7] = ft_dec_to_hex(ct % 16);
	while (i < 8)
		write(1, &nbr[i++], 1);
}

void	ft_print_hexdump(char *buff,int n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		write(1, " ", 1);
		ft_char_to_hex(buff[i]);
		i ++;
	}
	while (i < 16)
	{
		write(1, "   ", 3);
		i ++;
	}
	write(1, "\n", 1);
}

void	ft_print_chars(char *buff, int n)
{
	int	i;
	
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

void	ft_print_hexdump_C(char *buff, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		write(1, " ", 1);
		if (!(i % 8))
			write(1, " ", 1);
		ft_char_to_hex(buff[i]);
	}
	while (i < 16)
	{
		if (!(i % 8))
			write(1, " ", 1);
		write(1, "   ", 3);
		i++;
	}
	ft_print_chars(buff, n);
}

void	ft_print(char *buff, int n)
{
	ft_print_offset(g_offset);
	if (g_option)
		ft_print_hexdump_C(buff, n);
	else
		ft_print_hexdump(buff, n);
	g_offset += n;
}
