/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 19:36:24 by jubarbie          #+#    #+#             */
/*   Updated: 2015/10/25 21:49:18 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int	main(int argv, char **argc)
{
	int grid[9][9];
	int dirg[9][9];

	if (argv != 10)
		write(1, "Erreur\n", 7);
	else if (ft_init_grid(grid, argc))
	{
		ft_init_grid(dirg, argc);
		if ((ft_fill_sudoku(grid, 0, 0)) &&
		(ft_fill_backward_sudoku(dirg, 0, 0)))
			if (!ft_grid_is_same(grid, dirg))
			{
				write(1, "Erreur\n", 7);
				return (0);
			}
		ft_print_grid(grid);
	}
	else
		write(1, "Erreur\n", 7);
	return (0);
}
