/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 00:51:48 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/06 00:16:42 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin)
{
	if (!(begin->next))
		return (begin);
	return (ft_list_last(begin->next));
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	if (begin_list1)
	{
		tmp = ft_list_last(*begin_list1);
		tmp->next = begin_list2;
	}
	else
		begin_list1 = begin_list2;
}
