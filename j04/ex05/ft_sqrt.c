/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:39:09 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/25 00:28:39 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;
	int j;
	int k;

	if (nb <= 0)
		return (0);
	i = 1;
	j = 0;
	k = 0;
	while (k < nb)
	{
		k += i;
		i += 2;
		j++;
	}
	if (k == nb)
		return (j);
	return (0);
}
