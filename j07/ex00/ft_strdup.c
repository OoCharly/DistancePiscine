/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 12:06:59 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/02 18:13:03 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*cpy;

	len = 0;
	i = 0;
	while (src[i])
	{
		len++;
		i++;
	}
	i = 0;
	if (!(cpy = malloc(sizeof(*cpy) * (len + 1))))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = src[i];
	return (cpy);
}
