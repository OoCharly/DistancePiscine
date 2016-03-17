/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:10:30 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 18:51:21 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

int	ft_get_next_line(const int fd, char **line)
{
	static char	*buff;
	if (!buff)
	{
		if (!(buff = malloc(sizeof(*buff) * BUFF_SIZE)))
			return (-1);
	}

}

