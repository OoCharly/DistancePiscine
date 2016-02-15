/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 16:46:21 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/21 07:34:51 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_my_pow10(int n)
{
	int i;
	int p;

	p = 10;
	i = 1;
	if (n == 0)
		return (1);
	while (i++ < n)
		p *= 10;
	return (p);
}

void	ft_my_putnbr(int n, int t)
{
	int i;

	i = t;
	if (n == 0)
		ft_putchar('0');
	else
	{
		while (i-- > 0)
		{
			ft_putchar(((n / ft_my_pow10(i)) % 10) + '0');
		}
	}
}

int		ft_compare(int n, int nb)
{
	int tab[n];
	int i;

	i = 0;
	while (i++ <= n)
		(tab[i - 1]) = nb / ft_my_pow10(n - i - 1);
	i = 0;
	while (i++ < n)
	{
		if (tab[i - 1] >= tab[i])
			return (0);
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int i;
	int stahp;
	int nb;

	i = 0;
	nb = 12345678 / ft_my_pow10(9 - n);
	stahp = 123456789;
	while (nb < (stahp / ft_my_pow10(9 - n)))
	{
		if (ft_compare(n, nb) == 1)
			ft_my_putnbr(nb, n);
		nb++;
		ft_putchar(' ');
	}
	ft_my_putnbr(stahp / ft_my_pow10(9 - n), n);
}
