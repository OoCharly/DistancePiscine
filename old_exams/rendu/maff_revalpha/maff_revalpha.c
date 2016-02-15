/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern </var/mail/cdesvern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:15:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/12 10:21:56 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(){
	char	maj;
	char	min;

	min = 'z';
	maj = 'Y';
	while (maj >= 'A')
	{
		write(1, &min, 1);
		write(1, &maj, 1);
		min -= 2;
		maj -= 2;
	}
	min = '\n';
	write(1, &min, 1);
	return (0);
}
