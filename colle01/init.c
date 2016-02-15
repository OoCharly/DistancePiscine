/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 18:06:35 by jubarbie          #+#    #+#             */
/*   Updated: 2015/10/25 21:42:11 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_grid(int grid[9][9])
{
	int		i;
	int		j;
	char	nb;
	char	nl;

	i = 0;
	nl = '\n';
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			nb = grid[i][j] + 48;
			write(1, &nb, 1);
			if (j != 8)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, &nl, 1);
	}
}

int		ft_init_grid(int grid[9][9], char **argc)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if ((argc[i + 1][j]) == '.')
				grid[i][j] = 0;
			else if ((argc[i + 1][j] >= '0') && (argc[i + 1][j] <= '9'))
				grid[i][j] = argc[i + 1][j] - 48;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_grid_is_same(int grid[9][9], int dirg[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (grid[i][j] != dirg[i][j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
