/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 20:47:46 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 21:04:49 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	else
		return (1 + max(btree_level_count(root->left),
		btree_level_count(root->right)));
}
