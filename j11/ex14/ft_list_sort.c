/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 01:07:30 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/04 17:04:21 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

wap(t_list *a, t_list *b)
{
	void		*t;

	t = a->data;
	a->data = b->data;
	b->data = t;
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
	t_list		*temp;

	if (!begin_list)
		return (NULL);
	i = 0;
	temp = begin_list;
	while (begin_list->next && i++ < nbr)
		temp = temp->next;
	return (temp);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		len;
	int		ct;


	len = ft_list_size(*begin_list);
	i = 0;
	ct = 1;
	while (ct < len)
	{
		while (i < len - ct)
		{

			if ((*cmp)(at(*begin_list, i)->data, at(*begin_list, i + 1)->data) > 0)

				ft_swap(at(*begin_list, i), at(*begin_list, i + 1));
			i++;
		}
		i = 0;
		ct++;
	}
}
