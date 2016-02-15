/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:02:56 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/13 20:41:54 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct		s_map
{
	char		vide;
	char		obstacle;
	char		plein;
	int			n_ligne;
	int			len;
}			t_map;

typedef	struct		s_bsq
{
	int		x;
	int		y;
	int		len;
}			t_bsq

t_bsq			g_bsq;
t_map			g_map;
int		ft_get_info_map(int fd);

#endif