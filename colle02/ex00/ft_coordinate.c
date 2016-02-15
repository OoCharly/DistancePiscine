/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <amansour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 12:31:39 by amansour          #+#    #+#             */
/*   Updated: 2015/11/01 19:45:04 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_coordinate(char *str, int *ptrx, int *ptry)
{
	int i;

	i = 0;
	*ptry = 0;
	*ptrx = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			(*ptry)++;
		else
			(*ptrx)++;
		i++;
	}
	if ((*ptry) != 0)
		(*ptrx) = (*ptrx) / (*ptry);
}
