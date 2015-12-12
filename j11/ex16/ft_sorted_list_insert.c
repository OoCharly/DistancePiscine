/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern </var/mail/cdesvern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:22:06 by cdesvern          #+#    #+#             */
/*   Updated: 2015/12/12 18:03:33 by cdesvern         ###   ########.fr       */
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

	if (!*begin_list)
		ft_create_elem(data);
	if (cmp(data, (*begin_list)->data) < 0)
		ft_list_push_front(begin_list, data);
	else
	{
		while ((*begin_list)->next)
		{
			if (cmp(data, (*begin_list)->next->data) <= 0)
			{
				n_elem = ft_create_elem(data);
				n_elem->next = (*begin_list)->next;
				(*begin_list)->next = n_elem;
				return ((void)0);
			}
			*begin_list = (*begin_list)->next;
		}
		(*begin_list)->next = ft_create_elem(data);
	}
}
