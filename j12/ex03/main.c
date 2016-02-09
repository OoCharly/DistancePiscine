/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:11:42 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/09 17:12:55 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

int		g_option;

int		ft_next_fd(int *fd, int *i, char **av)
{
	i++;
	if (av[i])
	{
		if (ft_open(av[i], fd) < 0)
			return(ft_next_fd(fd, i, av));
		else
			return (0);
	}
	else
		return (-1);
}

int		ft_get_option_pos(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-c"))
		{
			g_option = 1;
			return (i);
		}
		i++;
	}
	g_option = 0;
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		opt;

	opt = ft_get_option_pos(av);
	if (ac < 2 || (ac == 2 && opt) )
		return (0);
	i = 1;
	if (g_option)
		i++;
	while (av[i])
	{

