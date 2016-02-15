/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:06:32 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/22 18:41:08 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	printf("%s", "THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour == 0 || hour == 24)
		printf("%d.00 A.M. AND %d.00 A.M.\n", 12, 1);
	else if (hour == 12)
		printf("%d.00 P.M. AND %d.00 P.M.\n", 12, 1);
	else if (hour == 11)
		printf("%d.00 A.M. AND %d.00 P.M.\n", 11, 12);
	else if (hour == 23)
		printf("%d.00 P.M. AND %d.00 A.M.\n", 11, 12);
	else if (hour > 12)
		printf("%d.00 P.M. AND %d.00 P.M.\n", hour - 12, hour - 11);
	else
		printf("%d.00 A.M. AND %d.00 A.M.\n", hour, hour + 1);
}
