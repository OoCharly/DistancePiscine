/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:30:26 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/25 15:37:38 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	t_byte	*b;
	int	i;
	
	if (!(b = (t_byte*)malloc(sizeof(t_byte) * size)))
		return (NULL);
	while (i < size)
	{
		*(b + i) = 0;
		i++;
	}
	return (b);
}
