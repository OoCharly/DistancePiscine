/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:50:56 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/28 07:52:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;
	int				ct;

	i = 0;
	j = 0;
	while (dest[i] && i + 1 < size)
		i++;
	if (i == size)
		return (i);
	while (i < size && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	while (src[j])
	{
		i++;
		j++;
	}
	return (i + 1);
}
