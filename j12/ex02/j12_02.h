/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j12.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:01:30 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/28 15:22:32 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J12_02_H
# define J12_02_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

int		ft_puterr(char *fn, int er);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_compress(int ac, char **av, int opt);
void	ft_putstr(char *str, int out);
int		ft_fsize(char *fn);
int		ft_offset(char **av, int opt, int size);
int		ft_tail(char *fn, int offset);

#endif
