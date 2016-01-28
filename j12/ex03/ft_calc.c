/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:40:32 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/27 22:29:00 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

void	ctooct(char c)
{
	char out[3];

	out[0] = c / 64 + 48;
	out[1] = (c % 64) / 8 + 48;
	out[2] = c % 8 + 48;
	write(1, out, 3);
}

char	ft_itoh(int nbr)
{
	char	out;

	out = 48;
	if (nbr < 10)
	{
		out += nbr;
		return (out);
	}
	if (nbr == 10)
		return ('a');
	if (nbr == 11)
		return ('b');
	if (nbr == 12)
		return ('c');
	if (nbr == 13)
		return ('d');
	if (nbr == 14)
		return ('e');
	if (nbr == 15)
		return ('f');
	return ('u');
}

void	ft_char_to_hex(char a)
{
	char out[2];

	out[0] = ft_itoh(a / 16);
	out[1] = ft_itoh(a %16);
	write(1, out, 2);
}
