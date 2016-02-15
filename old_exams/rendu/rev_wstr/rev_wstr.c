/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern </var/mail/cdesvern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:34:10 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/12 12:47:29 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (str)
		write(1, str++, 1);
}

int		ft_strlen(char *str)
{
	int	i = 0;
	
	while (str[i])
		i++;
	return (i);
}

void	ft_str_rev_wcpy(char *str)
{
	int		i;
	int		w;

	w = 0;
	i = ft_strlen(str) - 1;
	while (i>0)
	{
		if (str[i - 1] == '\t' || str[i - 1] == ' ')
		{
			w = i;
			while(str[i] && str[i] != '\t' && str[i] != ' ')
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, &str[w - 1], 1);
			i = w;
		}
		i--;
	}
	while (str[i]  && str[i] != '\t' && str[i] != ' ')
		write(1, &str[i++], 1);
}

int		main(int ac, char **av)
{
	char	nl;

	nl = '\n';
	if (ac != 2)
	{
		write(1, &nl, 1);
		return (0);
	}
	ft_str_rev_wcpy(av[1]);
	write(1, &nl, 1);
	return (0);
}
