/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 17:02:14 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/01 20:32:31 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLLE_H
# define FT_COLLE_H

char	ft_t0(int i, int j, int x, int y);
char	ft_t1(int i, int j, int x, int y);
char	ft_t2(int i, int j, int x, int y);
char	ft_t3(int i, int j, int x, int y);
char	ft_t4(int i, int j, int x, int y);

char	(*g_test[5])(int, int, int, int) = {ft_t0, ft_t1, ft_t2, ft_t3, ft_t4};

#endif
