/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:56:36 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/14 19:29:10 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static inline int	ft_itoutfp2(wchar_t c)
{
	if (c <= 0x1FFFFF)
	{
		ft_putchar((unsigned char)(0xF0 | (c >> 18)));
		ft_putchar((unsigned char)(0x80 | ((c >> 12) & 0x3F)));
		ft_putchar((unsigned char)(0x80 | ((c >> 6) & 0x3F)));
		ft_putchar((unsigned char)(0x80 | (c & 0x3F)));
		return (4);
	}
	return (0);
}

int					ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		ft_putchar((unsigned char)c);
		return (1);
	}
	else if (c <= 0x7FF)
	{
		ft_putchar((unsigned char)(0xC0 | (c >> 6)));
		ft_putchar((unsigned char)(0x80 | (c & 0x3F)));
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((unsigned char)(0xE0 | (c >> 12)));
		ft_putchar((unsigned char)(0x80 | ((c >> 6) & 0x3F)));
		ft_putchar((unsigned char)(0x80 | (c & 0x3F)));
		return (3);
	}
	else
		return (ft_itoutfp2(c));
}
