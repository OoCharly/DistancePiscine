/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:48:33 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 13:54:43 by cdesvern         ###   ########.fr       */
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
	if (len == 0)
		i++;
	while (i < n)
	{
		new_str[i + len - 1] = tmp[i - 1];
		i++;
	}
	new_str[i + len - 1] = -1;
	return (new_str);
}

char	*ft_file_to_string(char *file, char *filename)
{
	int		n;
	char	*tmp;
	int		i;
	int		fd;

	fd = ft_open(filename);
	if (fd < 0)
		return (file);
	i = 0;
	n = 4000;
	tmp = malloc(sizeof(*tmp) * 4000);
	while (n == 4000)
	{
		n = read(fd, tmp, 4000);
		tmp[n] = -1;
		if (n != 0)
			file = ft_concat_realloc(file, tmp, n + 1);
		i++;
	}
	if (close(fd) < 0)
		ft_puterr(filename, errno);
	return (file);
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
	char	*file;

	opt = ft_get_option_pos(av);
	if (ac < 2 || (ac == 2 && opt))
		return (0);
	if (!(file = malloc(sizeof(char))))
		return (1);
	*file = -1;
	i = 1;
	while (av[i])
	{
		if (i != opt)
			file = ft_file_to_string(file, av[i]);
		i++;
	}
	ft_print_offset(ft_hexdump(opt, file));
	write(1, "\n", 1);
	return (0);
}
