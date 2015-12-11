/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 02:00:23 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 18:38:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void			ft_elem_swap(t_list **elem1, t_list **elem2)
{
	void			*tmp_data;

	tmp_data = (*elem1)->data;
	(*elem1)->data = (*elem2)->data;
	(*elem2)->data = tmp_data;
}

unsigned int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*tmp;

	tmp = begin_list;
	i = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list			*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 1;
	while (begin_list->next && i < nbr)
	{
		i++;
		begin_list = begin_list->next;
	}
	if (i < nbr)
		return (NULL);
	return (begin_list);
}

void			ft_list_reverse_fun(t_list *begin_list)
{
	t_list			*tmp1;
	t_list			*tmp2;
	unsigned int	list_size;
	unsigned int	i;
	unsigned int	j;

	if (!begin_list)
		return ;
	list_size = ft_list_size(begin_list);
	i = 1;
	j = list_size;
	while (i != j && i != (list_size / 2 + 1))
	{
		tmp1 = ft_list_at(begin_list, i);
		tmp2 = ft_list_at(begin_list, j);
		ft_elem_swap(&tmp1, &tmp2);
		i++;
		j--;
	}
}
