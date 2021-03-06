/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:24:33 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/05 15:14:38 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOS_H
# define FT_PROTOS_H

typedef struct	s_opp
{
	char		*opp;
	void		(*f)(int, int);
}				t_opp;

void			ft_add(int a, int b);
void			ft_sub(int a, int b);
void			ft_mul(int a, int b);
void			ft_div(int a, int b);
void			ft_mod(int a, int b);
void			ft_usage(int a, int b);

void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
void			ft_putnbr(long nb);

#endif
