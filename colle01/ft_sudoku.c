/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 20:45:45 by jubarbie          #+#    #+#             */
/*   Updated: 2015/10/25 21:49:47 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_is_available(int grid[][9], int row, int col, int nb)
{
	int i;
	int row_start;
	int col_start;

	row_start = (row / 3) * 3;
	col_start = (col / 3) * 3;
	i = 0;
	while (i < 9)
	{
		if (grid[row][i] == nb)
			return (0);
		if (grid[i][col] == nb)
			return (0);
		if (grid[row_start + (i % 3)][col_start + (i / 3)] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		ft_fill_sudoku(int grid[][9], int row, int col)
{
	if (row < 9 && col < 9)
	{
		if (grid[row][col] != 0)
		{
			if ((col + 1) < 9)
				return (ft_fill_sudoku(grid, row, col + 1));
			else if ((row + 1) < 9)
				return (ft_fill_sudoku(grid, row + 1, 0));
			else
				return (1);
		}
		else
			return (ft_fill_forward(grid, row, col, 0));
	}
	else
		return (1);
}

int		ft_fill_backward_sudoku(int grid[][9], int row, int col)
{
	if (row < 9 && col < 9)
	{
		if (grid[row][col] != 0)
		{
			if ((col + 1) < 9)
				return (ft_fill_backward_sudoku(grid, row, col + 1));
			else if ((row + 1) < 9)
				return (ft_fill_backward_sudoku(grid, row + 1, 0));
			else
				return (1);
		}
		else
			return (ft_fill_backward(grid, row, col, 8));
	}
	else
		return (1);
}

int		ft_fill_backward(int grid[][9], int row, int col, int i)
{
	while (i >= 0)
	{
		if (ft_is_available(grid, row, col, i + 1))
		{
			grid[row][col] = i + 1;
			if ((col + 1) < 9)
			{
				if (ft_fill_backward_sudoku(grid, row, col + 1))
					return (1);
				grid[row][col] = 0;
			}
			else if ((row + 1) < 9)
			{
				if (ft_fill_backward_sudoku(grid, row + 1, 0))
					return (1);
				grid[row][col] = 0;
			}
			else
				return (1);
		}
		--i;
	}
	return (0);
}

int		ft_fill_forward(int grid[][9], int row, int col, int i)
{
	while (i < 9)
	{
		if (ft_is_available(grid, row, col, i + 1))
		{
			grid[row][col] = i + 1;
			if ((col + 1) < 9)
			{
				if (ft_fill_sudoku(grid, row, col + 1))
					return (1);
				grid[row][col] = 0;
			}
			else if ((row + 1) < 9)
			{
				if (ft_fill_sudoku(grid, row + 1, 0))
					return (1);
				grid[row][col] = 0;
			}
			else
				return (1);
		}
		++i;
	}
	return (0);
}
