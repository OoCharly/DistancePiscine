/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 00:54:36 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/20 22:17:36 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int a;
	int b;

	b = 0;
	a = 0;
	while (a <= 9899)
	{
		if ((a / 1000 <= (a % 100) / 10) && ((a % 1000) / 100 < a % 10))
		{
			ft_putchar('0' + (a / 1000));
			ft_putchar('0' + (a % 1000) / 100);
			ft_putchar(' ');
			ft_putchar('0' + (a % 100) / 10);
			ft_putchar('0' + a % 10);
			if (a != 9899)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		a++;
	}
}
