/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 20:46:20 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 18:42:01 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_free_list(t_list *list)
{
	if (list->next)
		ft_free_list(list->next);
	free(list);
}

void	ft_list_clear(t_list **begin_list)
{
	if (begin_list)
	{
		if (*begin_list)
		{
			if ((*begin_list)->next)
				ft_free_list((*begin_list)->next);
			free(*begin_list);
		}
		*begin_list = NULL;
	}
}
