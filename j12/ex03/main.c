/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:48:33 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/27 17:32:16 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

int	ft_get_option_pos(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-c"))
			return (i);
		i++;
	}
	return (-1);
}

int	main(int ac, char **av)
{
	int	i;
	int	opt;
	int	out;

	if (ac <= 2)
		return (0);
	i = 1;
	opt = ft_get_option_pos(av);
	if (opt < 0)
		return (1);
	while (av[i])
	{
		if (i != opt)
		{
			if (ft_read_file(av[i], av[0]))
				out = 1;
		}
		i++;
	}
	return (out);
}
