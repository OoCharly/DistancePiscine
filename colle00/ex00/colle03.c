/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 17:10:58 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/17 19:07:06 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void colle(int x, int y)
{
	int i; 
	int j;

	i = 0;
	j = 0;
	if ((x < 0) || (y < 0))
	{
		write(2 ,"ERROR : one (or both)of your input is negative\n",49);
		write(1 ,"Cette fonction est TrollProof\n" ,31);		
	}
	while(i++ < y)
	{
    	while(j++ < x)
		{
			if ((j == 1) && ((i == 1) || (i == y)))
				ft_putchar('A');
			else if ((j == x) && ((i == 1) || (i == y)))
				ft_putchar('C');
			else if((i == 1) || (j == 1) || (j == x) || (i == y))
            	ft_putchar('B');
			else
            	ft_putchar(' ');
		}
		j=0;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
