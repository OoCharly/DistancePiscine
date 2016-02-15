/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 18:36:58 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/21 18:37:02 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_my_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n))
		n++;
	return (n);
}

char	*ft_strrev(char *str)
{
	char	temp;
	int		i;
	int		n;

	i = 0;
	n = ft_my_strlen(str);
	while (i < n / 2)
	{
		temp = *(str + i);
		*(str + i) = *(str + n - 1 - i);
		*(str + n - 1 - i) = temp;
		i++;
	}
	return (str);
}
