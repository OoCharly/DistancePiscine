/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 20:50:49 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/12 16:19:42 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_node_fit(t_btree *node, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*fit;

	if ((*cmpf)(node->item, item) < 0)
	{
		if (node->right)
			btree_node_fit(node->right, item, cmpf);
		else
		{
			fit = btree_create_node(item);
			node->right = fit;
		}
	}
	if ((*cmpf)(node->item, item) > 0)
	{
		if (node->left)
			btree_node_fit(node->left, item, cmpf);
		else
		{
			fit = btree_create_node(item);
			node->left = fit;
		}
	}
}

void	btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	if (!*root)
		*root = btree_create_node(item);
	else
		btree_node_fit(*root, item, cmpf);
}
