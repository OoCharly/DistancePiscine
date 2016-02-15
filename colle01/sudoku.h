/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 18:28:26 by jubarbie          #+#    #+#             */
/*   Updated: 2015/10/25 21:34:47 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

int		ft_init_grid(int grid[9][9], char **argc);
int		ft_is_available(int grid[][9], int row, int col, int numb);
int		ft_fill_sudoku(int grid[][9], int row, int col);
int		ft_fill_backward_sudoku(int grid[][9], int row, int col);
int		ft_fill_forward(int grid[][9], int row, int col, int i);
int		ft_fill_backward(int grid[][9], int row, int col, int i);
int		ft_grid_is_same(int grid[9][9], int dirg[9][9]);
void	ft_print_grid(int grid[9][9]);

#endif
