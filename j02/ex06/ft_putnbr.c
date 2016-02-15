/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 03:54:47 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/21 08:56:29 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_pow10(int n)
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

void	ft_putnbr(int n)
{
	int	i;
	int	temp;

	i = 10;
	if (n == 0)
		ft_putchar('0');
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			temp = -(n + 1);
		}
		while (temp / ft_pow10(i - 1) == 0)
			i--;
		while (i-- > 0)
		{
			if ((n < 0) && (i == 0))
				ft_putchar(((temp / ft_pow10(i)) % 10) + 1 + '0');
			else
				ft_putchar(((temp / ft_pow10(i)) % 10) + '0');
		}
	}
}
