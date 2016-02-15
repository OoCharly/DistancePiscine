/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 00:25:58 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/23 00:55:05 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_rec_collatz_conjecture(unsigned int base, unsigned int index)
{
	if (base == 1)
		return (index);
	index++;
	if ((base % 2) == 0)
		return (ft_rec_collatz_conjecture(base / 2, index));
	return (ft_rec_collatz_conjecture(3 * base + 1, index));
}

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	unsigned int index;

	index = (0);
	return (ft_rec_collatz_conjecture(base, index));
}
