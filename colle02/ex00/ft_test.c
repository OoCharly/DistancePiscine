/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 18:20:13 by vafanass          #+#    #+#             */
/*   Updated: 2015/11/01 20:32:28 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_t0(int i, int j, int x, int y)
{
	char kek;

	kek = 0;
	if ((i == 1) || (j == 1) || (i == x) || (j == y))
	{
		if ((i == 1) && (j == 1))
			kek = 'o';
		else if (((i == x) && (j == 1)) || ((i == 1) && (j == y)))
			kek = 'o';
		else if ((i == x) && (j == y))
			kek = 'o';
		else if (j == 1 || j == y)
			kek = '-';
		else
			kek = '|';
	}
	else
		kek = ' ';
	return (kek);
}

char	ft_t1(int i, int j, int x, int y)
{
	char kek;

	kek = 0;
	if ((i == 1) || (j == 1) || (i == x) || (j == y))
	{
		if (i == 1 && j == 1)
			kek = '/';
		else if (i == x && j == 1)
			kek = 92;
		else if (i == 1 && j == y)
			kek = 92;
		else if (i == x && j == y)
			kek = '/';
		else if (i == 1 || i == x)
			kek = '*';
		else if (j == 1 || j == y)
			kek = '*';
	}
	else
		kek = ' ';
	return (kek);
}

char	ft_t2(int i, int j, int x, int y)
{
	char kek;

	kek = 0;
	{
		if ((i == 1) || (j == 1) || (i == x) || (j == y))
		{
			if (i == 1 && j == 1)
				kek = 'A';
			else if (i == x && j == 1)
				kek = 'A';
			else if (i == 1 && j == y)
				kek = 'C';
			else if (i == x && j == y)
				kek = 'C';
			else if (i == 1 || i == x)
				kek = 'B';
			else if (j == 1 || j == y)
				kek = 'B';
		}
		else
			kek = ' ';
	}
	return (kek);
}

char	ft_t3(int i, int j, int x, int y)
{
	char kek;

	kek = 0;
	{
		if ((i == 1) || (j == 1) || (i == x) || (j == y))
		{
			if (i == 1 && j == 1)
				kek = 'A';
			else if (i == x && j == 1)
				kek = 'C';
			else if (i == 1 && j == y)
				kek = 'A';
			else if (i == x && j == y)
				kek = 'C';
			else if (i == 1 || i == x)
				kek = 'B';
			else if (j == 1 || j == y)
				kek = 'B';
		}
		else
			kek = ' ';
	}
	return (kek);
}

char	ft_t4(int i, int j, int x, int y)
{
	char kek;

	kek = 0;
	{
		if ((i == 1) || (j == 1) || (i == x) || (j == y))
		{
			if ((i == 1) && (j == 1))
				kek = 'A';
			else if (((i == x) && (j == 1)) || ((i == 1) && (j == y)))
				kek = 'C';
			else if ((i == x) && (j == y))
				kek = 'A';
			else
				kek = 'B';
		}
		else
			kek = ' ';
	}
	return (kek);
}
