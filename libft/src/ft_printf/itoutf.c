/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoutf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:09:36 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/14 18:23:20 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** masks[0] = 0xC080;
** masks[1] = 0xE08080;
** masks[2] = 0xF0808080;
** masks[3] = 0xF880808080;
** masks[4] = 0xFC8080808080;
*/

static inline char	*ft_itoutfp2(char *buf, int num)
{
	if (num <= 0xFFFF)
	{
		buf[0] = (unsigned char)(0xE0 | (num >> 12));
		buf[1] = (unsigned char)(0x80 | ((num >> 6) & 0x3F));
		buf[2] = (unsigned char)(0x80 | (num & 0x3F));
		return (buf);
	}
	else if (num <= 0x1FFFFF)
	{
		buf[0] = (unsigned char)(0xF0 | (num >> 18));
		buf[1] = (unsigned char)(0x80 | ((num >> 12) & 0x3F));
		buf[2] = (unsigned char)(0x80 | ((num >> 6) & 0x3F));
		buf[3] = (unsigned char)(0x80 | (num & 0x3F));
		return (buf);
	}
	return (NULL);
}

char				*ft_itoutf(int num)
{
	char *str;

	str = ft_strnew(4);
	if (num < 0)
		return (NULL);
	if (num <= 0x7F)
	{
		str[0] = (unsigned char)num;
		return (str);
	}
	else if (num <= 0x7FF)
	{
		str[0] = (unsigned char)(0xC0 | (num >> 6));
		str[1] = (unsigned char)(0x80 | (num & 0x3F));
		return (str);
	}
	else
		return (ft_itoutfp2(str, num));
}
