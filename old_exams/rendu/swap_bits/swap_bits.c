/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern </var/mail/cdesvern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:07:51 by cdesvern          #+#    #+#             */
/*   Updated: 2016/01/12 11:19:19 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char	octet)
{
	unsigned char	tmp;

	tmp = 0;
	if (octet / 128)
		tmp += 8;
	if ((octet % 128) / 64)
		tmp += 4;
	if ((octet % 64) / 32)
		tmp += 2;
	if ((octet % 32) / 16)
		tmp++;
	if ((octet % 16) / 8)
		tmp += 128;
	if ((octet % 8) / 4)
		tmp += 64;
	if ((octet % 4) / 2)
		tmp += 32;
	if (octet % 2)
		tmp += 16;
	return (tmp);
}
