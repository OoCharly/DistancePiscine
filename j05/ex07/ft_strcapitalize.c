/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 15:55:18 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/28 07:19:34 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		i_am_up_case(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}

int		i_am_low_case(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	return (0);
}

int		i_am_space_and_cie(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '+' || c == '-')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (i_am_low_case(str[0]))
		str[0] -= 32;
	while (str[i])
	{
		if (i_am_low_case(str[i]) && i_am_space_and_cie(str[i - 1]))
			str[i] -= 32;
		else if (i_am_up_case(str[i]) && !i_am_space_and_cie(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
