/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 13:17:01 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/23 17:30:19 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int		ft_create_init_tabs(int **neg, int **line)
{
	int		i;

	if (!(*neg = malloc(sizeof(int) * g_map.len)))
		return (0);
	if (!(*line = malloc(sizeof(int) * g_map.len)))
		return (0);
	i = 0;
	while (i < g_map.len)
	{
		(*neg)[i] = 0;
		(*line)[i] = 0;
		i++;
	}
	return (1);
}
