/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 12:43:43 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/04 03:50:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power > 0)
	{
		return (nb * ft_power(nb, power - 1));
	}
	else
	{
		return (0);
	}
}

int		ft_size(int v, int b)
{
	int		s;

	s = 0;
	while (ft_power(b, s) <= v)
		s++;
	return (s);
}

int		ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

int		ft_from_to_ten(char *nbr, char *base_from)
{
	int		i;
	int		j;
	int		nb;

	nb = 0;
	i = -1;
	while (nbr[++i] != '\0')
	{
		j = -1;
		while (base_from[++j] != nbr[i])
			if (base_from[j + 1] == '\0')
				return (-1);
		nb = nb * ft_strlen(base_from) + j;
	}
	return (nb);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		nb;
	int		s;

	nb = ft_from_to_ten(nbr, base_from);
	if (nb < 0)
		return (nbr);
	s = ft_size(nb, ft_strlen(base_to));
	nbr = (char*)malloc(sizeof(char) * (s + 1));
	i = 0;
	if (s == 0)
		return ("0");
	while (i++ < s)
	{
		nbr[s - i] = base_to[nb % ft_strlen(base_to)];
		nb = nb / ft_strlen(base_to);
	}
	nbr[s] = '\0';
	return (nbr);
}
