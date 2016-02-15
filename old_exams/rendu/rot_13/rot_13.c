/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern </var/mail/cdesvern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:25:39 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/12 11:03:59 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	pimp_my_char(char a)
{
	if ((a <= 'z' && a >= 'n') || (a <= 'Z' && a >= 'N'))
		a = a - 13;
	else if ((a >= 'A' && a <= 'M') || (a <= 'm' && a >= 'a'))
		a += 13;
	return (a);
}

int		main(int ac, char **av)
{
	int		i;
	char	rtn;
	char	t;

	rtn = '\n';
	i = 0;
	t = '\0';
	if (ac != 2)
	{
		write(1, &rtn, 1);
		return (0);
	}
	while (av[1][i])
	{
		t = pimp_my_char(av[1][i]);
		write(1, &t, 1);
		i++;
	}
	write(1, &rtn, 1);
	return (0);
}
