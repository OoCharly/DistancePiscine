/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:48:33 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 00:19:20 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j12_03.h"

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

char	*ft_file_to_string(int fd)
{
	int		n;
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	n = 4000;
	tmp = malloc(sizeof(*tmp) * 4000);
	while (n == 4000)
	{
		n = read(fd, tmp, pas);
		tmp[n] = '\0';
		if (n != 0)
			str = ft_concat_realloc(str, tmp, n + 1);
		i++;
	}
	str[((i - 1) * pas) + n] = '\0';
	return (str);
}

int	ft_get_option_pos(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "-c"))
			return (i);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	opt;
	int	fd;

	opt = ft_get_option_pos(av);
	if (ac < 2 || (ac == 2 && opt))
		return (0);
	i = 1;
	while (av[i])
	{
		if (i != opt)
		{
			fd = open(av[i], O_RDONLY);
			if (fd < 0)
				ft_puterr(av[i], errno);
			else
				ft_read_file(av[i], opt);
			if (fd >= 0)
			{
				if (close(fd) < 0)
					ft_puterr(ft, fn, errno);
			}
		}
		i++;
	}
	return (0);
}
