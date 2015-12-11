/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 20:27:53 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 23:48:39 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_first;

	new_first = ft_create_elem(data);
	new_first->next = *begin_list;
	*begin_list = new_first;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*new_list;

	i = 1;
	if (ac == 1)
		return (0);
	new_list = ft_create_elem(av[0]);
	while (i < ac - 1)
	{
		ft_list_push_front(&new_list, av[i]);
		i++;
	}
	return (new_list);
}
