/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 15:58:40 by jubarbie          #+#    #+#             */
/*   Updated: 2015/10/17 18:06:03 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	colle(int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j++ < y)
	{
		i = 0;
		while (i++ < x)
		{
			if ((i == 1) || (j == 1) || (i == x) || (j == y))
			{
				if ((i == 1) && (j == 1))
					ft_putchar('A');
				else if (((i == x) && (j == 1)) || ((i == 1) && (j == y)))
					ft_putchar('C');
				else if ((i == x) && (j == y))
					ft_putchar('A');
				else
					ft_putchar('B');
			}
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
