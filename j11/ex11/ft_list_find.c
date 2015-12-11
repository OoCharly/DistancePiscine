/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 00:27:20 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/06 17:16:14 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list)
	{
		while (begin_list)
		{
			if (!((*cmp)(begin_list->data, data_ref)))
				return (begin_list);
			begin_list = begin_list->next;
		}
	}
	return (NULL);
}
