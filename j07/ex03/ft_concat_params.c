/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:17:53 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/02 12:52:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n + 1);
}

void	ft_mother_of_concat(int argc, char **argv, char *tab)
{
	int	j;
	int	i;
	int cs;

	j = 0;
	cs = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			tab[i + cs] = argv[j][i];
			i++;
		}
		tab[i + cs] = '\n';
		cs += i + 1;
	}
	tab[cs - 1] = '\0';
}

char	*ft_concat_params(int argc, char **argv)
{
	int		t_len;
	int		i;
	char	*tab;

	t_len = 0;
	i = 0;
	while (++i < argc)
		t_len += ft_strlen(argv[i]);
	if (!(tab = malloc(sizeof(*tab) * t_len)))
		return ((char *)NULL);
	ft_mother_of_concat(argc, argv, tab);
	return (tab);
}
