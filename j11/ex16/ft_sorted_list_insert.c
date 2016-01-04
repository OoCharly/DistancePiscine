/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 18:31:27 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/04 17:26:30 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_first;

	new_first = ft_create_elem(data);
	new_first->next = *begin_list;
	*begin_list = new_first;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*n_elem;
	t_list	*temp;

	if (!*begin_list)
		ft_create_elem(data);
	if (cmp(data, (*begin_list)->data) < 0)
		ft_list_push_front(begin_list, data);
	else
	{
		temp = *begin_list;
		while (temp->next)
		{
			if (cmp(data, temp->next->data) <= 0)
			{
				n_elem = ft_create_elem(data);
				n_elem->next = temp->next;
				temp->next = n_elem;
				return ((void)0);
			}
			temp = temp->next;
		}
		(*begin_list)->next = ft_create_elem(data);
	}
}
