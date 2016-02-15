/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:24:09 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/03 20:06:15 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!(cpy = malloc(sizeof(*cpy) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = src[i];
	return (cpy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*tab_struct;
	int			i;

	if (!(tab_struct = malloc(sizeof(*tab_struct) * (ac))))
		return ((t_stock_par*)NULL);
	i = 0;
	while (i < ac)
	{
		tab_struct[i].size_param = ft_strlen(av[i]);
		tab_struct[i].str = av[i];
		tab_struct[i].copy = ft_strdup(av[i]);
		tab_struct[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	tab_struct[ac].str = 0;
	return (tab_struct);
}
