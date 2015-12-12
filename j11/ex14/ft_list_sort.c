/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 01:07:30 by cdesvern          #+#    #+#             */
/*   Updated: 2015/12/12 15:15:36 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_swap(t_list *a, t_list *b)
{
	void		*t;

	t = (a)->data;
	(a)->data = (b)->data;
	(b)->data = t;
}

int		ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	if (begin_list->next)
		return (1 + ft_list_size(begin_list->next));
	return (1);
}

t_list	*at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (!begin_list)
		return (NULL);
	i = 0;
	while (begin_list->next && i++ < nbr)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		len;
	int		ct;

	len = ft_list_size(*begin_list);
	i = 0;
	ct = 0;
	while (ct < len)
	{
		while (i < len - 2)
		{
			if ((*cmp)(at(*begin_list, i), at(*begin_list, i + 1)) > 0)
				ft_swap(at(*begin_list, i), at(*begin_list, i + 1));
			i++;
		}
		ct++;
	}
}
