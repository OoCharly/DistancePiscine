/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 00:30:07 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/04 02:57:02 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*n_link;

	n_link = *begin_list;
	if (*begin_list)
	{
		if (!((*cmp)((*begin_list)->data, data_ref)))
		{
			n_link = *begin_list;
			*begin_list = (*begin_list)->next;
			free(n_link);
			ft_list_remove_if(begin_list, data_ref, cmp);
		}
		else
		{
			ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
		}
	}
}
