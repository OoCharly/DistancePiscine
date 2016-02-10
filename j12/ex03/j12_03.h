/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j12_03.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:29:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/10 18:06:01 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J12_03_H
# define J12_03_H

# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

int		g_offset;
int		g_option;

char	ft_dec_to_hex(int a);
void	ft_char_to_hex(char a);
int		ft_puterr(char *fn, int er);
int		ft_create_buffer(int *fd, int *i, char **av, char *buff);
void	ft_print(char *buff, int n);
int		ft_next_fd(int *fd, int *i, char **av);
int		ft_open(char *filename, int *fd);
int		ft_strcmp(char *s1, char *s2);
int		we_are_legion(int *fd, int *i, char **av, char *buff);
void	ft_print_offset(int ct);

#endif
