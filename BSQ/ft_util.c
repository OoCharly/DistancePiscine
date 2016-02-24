/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:48:37 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/24 14:44:25 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoi(char *str, int j)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i <= j)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		n += str[i] - 48;
		n *= 10;
		i++;
	}
	return (n / 10);
}
