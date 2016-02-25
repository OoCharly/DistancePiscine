/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:08:14 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/25 20:19:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		neg;
	int		i;
	char	*out;

	neg = (n < 0) ? 1 : 0;
	i = 0;
	while (n / ft_pow_ten(i))
		i++;
	if (n == 0)
		i = 1;
	out = ft_strnew((size_t)(i + neg));
	if (neg)
		out[0] = '-';
	while (--i >= 0)
		out[neg++] = (char)((n / ft_pow_ten(i)) % 10 + 48);
	return (out);
}

unsigned int	ft_pow_ten(int i)
{
	if (i == 0)
		return (1);
	else
		return (10 * ft_pow_ten(i - 1));
}
