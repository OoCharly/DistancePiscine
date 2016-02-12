/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:11:42 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/12 15:24:57 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

int		ft_next_fd(int *fd, int *i, char **av)
{
	(*i) += 1;
	if (av[*i])
	{
		if (ft_open(av[*i], fd) < 0)
			return (ft_next_fd(fd, i, av));
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
		if (!ft_strcmp(av[i], "-C"))
		{
			g_option = 1;
			return (i);
		}
		i++;
	}
	g_option = 0;
	return (0);
}

void	ft_grand_final(char *buff, int temp)
{
	if (temp != 0)
		ft_print(buff, temp);
	ft_print_offset(g_offset);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int		i;
	int		opt;
	char	buff[16];
	int		fd;
	int		temp;

	temp = -1;
	opt = ft_get_option_pos(av);
	if (ac < 2 || (ac == 2 && opt))
		return (0);
	i = 1;
	if (g_option)
		i++;
	while (ft_open(av[i], &fd) < 0 && av[i])
		i++;
	if (av[i])
		temp = ft_create_buffer(&fd, &i, av, buff);
	while (temp == 16 && av[i])
	{
		ft_print(buff, temp);
		temp = we_are_legion(&fd, &i, av, buff);
	}
	if (temp >= 0)
		ft_grand_final(buff, temp);
	return (0);
}
