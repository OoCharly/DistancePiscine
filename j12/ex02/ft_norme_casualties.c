/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme_casualties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:49:57 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 15:26:17 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_02.h"

void	ft_display_name(char *str, int i)
{
	if (i != 1 && i != 3)
		write(1, "\n", 1);
	ft_putstr("==> ", 1);
	ft_putstr(str, 1);
	ft_putstr(" <==\n", 1);
}

int		ft_compress(int ac, char **av, int opt)
{
	int	i;
	int	out;
	int	ofs;

	out = 0;
	ofs = 0;
	i = 1;
	while (av[i])
	{
		if (i != opt && i != (opt - 1))
		{
			if (ft_fsize(av[i]) > 0)
			{
				if (ac > 4)
					ft_display_name(av[i], i);
				ofs = ft_offset(av, opt, ft_fsize(av[i]));
				ft_tail(av[i], ofs);
			}
			else
				out = 1;
		}
		i++;
	}
	return (out);
}
