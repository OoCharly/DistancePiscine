/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:13:20 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/25 17:19:21 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;

	out = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	ft_strcpy(out, ft_strcat(s1, s2));
	return (out);
}
