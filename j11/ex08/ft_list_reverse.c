/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:38:04 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/04 02:51:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	if (*begin_list == NULL)
		return ;
	tmp2 = NULL;
	tmp = *begin_list;
	if (!tmp || !(tmp->next))
		return ;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	while (tmp3)
	{
		tmp = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
		tmp2->next = tmp;
	}
	*begin_list = tmp2;
}
