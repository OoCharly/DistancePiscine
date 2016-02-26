/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:21:03 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 19:10:13 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (!(dst && src))
		return (0);
	i = 0;
	len = ft_strlen(dst);
	while (i < (size - 1))
	{
		*(dst + len + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (len + size - 1);
}
