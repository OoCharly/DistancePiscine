/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 20:40:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 13:41:15 by cdesvern         ###   ########.fr       */
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

void	we_are_legion(char *buff, char *a, int *ct, int opt)
{
	*ct += ft_print_hex(ct, buff, opt);
	if(i_am_legion(&buff[*ct], a))
	{
		write(1, "*\n", 2);
		*ct +=16;
		while(!incomplete_line(&buff[*ct]) && i_am_legion(&buff[*ct], a))
			*ct += 16;
	}	
}

int	incomplete_line(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (str[i] < 0)
			return (2 * ((i / 2) + (i % 2)));
		i++;
	}
	return (0);
}

int	ft_hexdump(int opt, char *buff)
{
	int		ct;
	char	a;

	a = -1;
	ct = 0;
	while (!(ct % 16))
	{
		ct += ft_print_hex(&ct, buff, opt);
		if (i_am_legion(&buff[ct], &a) && !(ct % 16))
			we_are_legion(buff, &a, &ct, opt);
	}
	return (ct);
}
