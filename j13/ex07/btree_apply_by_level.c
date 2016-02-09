/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 20:19:00 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/27 22:55:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_at_lvl(t_btree *root, void (applyf)(void *item,
				int current_level, int is_first), int lvl)
{
	if (lvl != 0)
	{
		btree_apply_at_lvl(root, applyf)

void	btree_apply_by_level(t_btree *root, void (applyf)(void *item,
				int current_level, int is_first))
{
	if (!root)
		return (0);
	(*applyf)(root->item, 0, 1);

