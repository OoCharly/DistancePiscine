/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j12_03.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:29:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/27 17:57:49 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J12_03_H
# define J12_03_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

void	ft_print_hex(int ct, int n, char *buff);
int		ft_puterr(char *ft, char *fn, int er);
void	ft_print_offset(int ct);
void	ctooct(char c);
char	ft_itoh(int nbr);
int		ft_strcmp(char *s1, char *s2);
int		ft_read_file(char *fn, char *ft);

#endif
