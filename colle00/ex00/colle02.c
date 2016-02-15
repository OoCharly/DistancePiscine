/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 11:36:18 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/17 19:15:25 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	colle(int x, int y)
{
	int i;
	int	j;

	i = 0;
	if ((x <= 0) || (y <= 0))
	{
		write(2, "ERROR : one (or both) of your input is negative\n", 49);
		write(1, "Cette fonction est Troll-Proof\n", 31);
	}
	while (i++ < y)
	{
		j = 0;
		while (j++ < x)
		{
			if ((i == 1) && ((j == 1) || (j == x)))
				ft_putchar('A');
			else if ((i == y) && ((j == 1) || (j == x)))
				ft_putchar('C');
			else if ((i == 1) || (j == 1) || (i == y) || (j == x))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
