/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:40:38 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/25 15:43:29 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int	i;

	i = 0;
	if (!size)
		return (NULL);
	if (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		*(s + i) = '\0';
		i++;
	}
	*(s + size) = '\0';
	return (s);
}
