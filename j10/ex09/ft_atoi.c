/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 07:19:54 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 14:31:41 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	i_am_number(int i, char *str)
{
	long	nbr;
	int		j;
	int		out;

	out = 0;
	nbr = 0;
	j = i;
	if (str[i] == '-' || str[i] == '+')
		j = i + 1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		nbr += str[j] - '0';
		nbr *= 10;
		j++;
	}
	if ((str[i] == '-') && nbr != 0)
		nbr = -nbr;
	out = nbr / 10;
	return (out);
}

long	ft_atoi(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' &&
		str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i] == '+' &&
		str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (i_am_number(i, &str[0]));
		if (str[i] != ' ' && str[i] != 9 && str[i] != 10)
			return (0);
		else
			i++;
	}
	return (0);
}
