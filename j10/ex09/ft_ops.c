/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 02:44:57 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 22:23:56 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_protos.h"

void	ft_add(int a, int b)
{
	long	tmp;

	tmp = a + b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_sub(int a, int b)
{
	long	tmp;

	tmp = a - b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_mul(int a, int b)
{
	long	tmp;

	tmp = a * b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_div(int a, int b)
{
	long	tmp;

	tmp = a / b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_mod(int a, int b)
{
	long	tmp;

	tmp = a % b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}
