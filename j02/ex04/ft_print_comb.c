/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 00:44:15 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/19 01:12:37 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int n;

	n = 12;
	while (n < 789)
	{
		if ((n / 100 < (n % 100) / 10) && ((n % 100) / 10 < n % 10))
		{
			ft_putchar((n / 100) + '0');
			ft_putchar(((n % 100) / 10) + '0');
			ft_putchar((n % 10) + '0');
			ft_putchar(',');
			ft_putchar(' ');
		}
		n++;
	}
	ft_putchar('7');
	ft_putchar('8');
	ft_putchar('9');
}
