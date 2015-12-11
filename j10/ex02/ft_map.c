/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 13:17:05 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 12:07:40 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*t_tab;

	i = 0;
	if (!(t_tab = malloc(sizeof(*t_tab) * length)))
		return ((int *)NULL);
	while (i < length)
	{
		t_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (t_tab);
}
