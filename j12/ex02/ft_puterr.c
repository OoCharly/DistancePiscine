/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:00:34 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 15:15:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_02.h"

void	ft_putstr(char *str, int out)
{
	while (*str)
	{
		write(out, str, 1);
		str++;
	}
}

int		ft_puterr(char *fn, int er)
{
	if (er == ENOMEM)
		return (-1);
	ft_putstr("cat", 2);
	ft_putstr(": cannot open '", 2);
	ft_putstr(fn, 2);
	ft_putstr("' for reading: ", 2);
	if (er == EACCES)
		ft_putstr("Permission denied\n", 2);
	if (er == ENOENT)
		ft_putstr("No such file or directory\n", 2);
	return (-1);
}
