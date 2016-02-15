/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:41:04 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/21 18:33:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_my_swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int ct;
	int i;

	i = 0;
	ct = 0;
	while (ct < size)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
				ft_my_swap((tab + i), (tab + i + 1));
			i++;
		}
		ct++;
		i = 0;
	}
}
