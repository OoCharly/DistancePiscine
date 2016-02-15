/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 18:05:00 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/01 20:34:20 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_concat_realloc(char *str, char *tmp, int n)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = ft_strlen(str);
	new_str = malloc(sizeof(*str) * (len + n + 1));
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	i = 0;
	while (i < n)
	{
		new_str[i + len] = tmp[i];
		i++;
	}
	return (new_str);
}

char	*ft_pipe_to_string(void)
{
	int		n;
	char	*str;
	char	*tmp;
	int		pas;
	int		i;

	i = 0;
	pas = 50;
	n = pas;
	tmp = malloc(sizeof(*tmp) * pas);
	str = malloc(0);
	while (n == pas)
	{
		n = read(0, tmp, pas);
		tmp[n] = '\0';
		if (n != 0)
			str = ft_concat_realloc(str, tmp, n + 1);
		i++;
	}
	str[((i - 1) * pas) + n] = '\0';
	return (str);
}
