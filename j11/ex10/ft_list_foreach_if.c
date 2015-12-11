/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 00:22:28 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/04 02:55:48 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *)
		, void *data_ref, int (*cmp)())
{
	if (begin_list)
	{
		while (begin_list)
		{
			if (!((*cmp)(begin_list->data, data_ref)))
				(*f)(begin_list->data);
			begin_list = begin_list->next;
		}
	}
}
