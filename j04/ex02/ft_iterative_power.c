/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:22:10 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/24 22:40:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int t;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	t = nb;
	while (i != power)
	{
		t *= nb;
		i++;
	}
	return (t);
}
