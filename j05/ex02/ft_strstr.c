/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 13:36:07 by cdesvern          #+#    #+#             */
/*   Updated: 2015/10/26 20:55:02 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n);
}

int		ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = n;
	while (i > 0)
	{
		if (*s1 != *s2)
		{
			if (*s1 < *s2)
				return (-1);
			return (1);
		}
		if (*s1 == '\0')
			return (0);
		i--;
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int l;

	l = ft_strlen(to_find);
	while (ft_strncmp(str, to_find, l) != 0)
	{
		str++;
		while (*str != *to_find)
		{
			if (*str == '\0')
				return ((char *)0);
			str++;
		}
	}
	return (str);
}
