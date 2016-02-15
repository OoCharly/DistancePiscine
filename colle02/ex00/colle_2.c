/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 17:20:23 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/01 20:29:45 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colle.h"
#include "ft_protos.h"
#include <stdlib.h>

char	*ft_colle(int x, int y, int f)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = malloc(sizeof(*str) * (y * (x + 1)) + 1);
	k = 0;
	i = 0;
	j = 0;
	while (i++ < y)
	{
		while (j++ < x)
		{
			str[k] = (g_test[f])(j, i, x, y);
			k++;
		}
		j = 0;
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';
	return (str);
}

void	ft_print_cmp_colle(int i, int x, int y, int flag)
{
	if (flag != 0)
		ft_putstr(" || ");
	ft_putstr("[colle-0");
	ft_putnbr(i);
	ft_putstr("] [");
	ft_putnbr(x);
	ft_putstr("] [");
	ft_putnbr(y);
	ft_putstr("]");
}

void	ft_print_rectangle(int x, int y, int *flag)
{
	if (x == y)
	{
		if (*flag != 0)
			ft_putstr(" || ");
		ft_putstr("[carre] [");
		ft_putnbr(x);
		ft_putstr("] [");
		ft_putnbr(y);
		ft_putstr("]");
		ft_putstr(" || ");
		ft_putstr("[rectangle] [");
		ft_putnbr(x);
		ft_putstr("] [");
		ft_putnbr(y);
		ft_putstr("]");
		*flag += 1;
	}
}

void	ft_cmp_colles(char *str)
{
	int	i;
	int x;
	int y;
	int	flag;

	flag = 0;
	i = 0;
	ft_coordinate(str, &x, &y);
	while (i < 5)
	{
		if (ft_strcmp(str, ft_colle(x, y, i)) == 0)
		{
			ft_print_cmp_colle(i, x, y, flag);
			flag++;
		}
		i++;
	}
	ft_print_rectangle(x, y, &flag);
	if (flag == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}
