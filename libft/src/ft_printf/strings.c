/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:57:55 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 15:08:23 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_wcs_to_buff(t_printf *data, int c)
{
	if (c <= 0x7F)
		ft_add_char_to_buff(data, (unsigned char)c);
	else if (c <= 0x7FF)
	{
		ft_add_char_to_buff(data, (unsigned char)(0xC0 | (c >> 6)));
		ft_add_char_to_buff(data, (unsigned char)(0x80 | (c & 0x3F)));
	}
	else if (c <= 0xFFFF)
	{
		ft_add_char_to_buff(data, (unsigned char)(0xE0 | (c >> 12)));
		ft_add_char_to_buff(data, (unsigned char)(0x80 | ((c >> 6) & 0x3F)));
		ft_add_char_to_buff(data, (unsigned char)(0x80 | (c & 0x3F)));
	}
	else if (c <= 0x1FFFFF)
	{
		ft_add_char_to_buff(data, (unsigned char)(0xF0 | (c >> 18)));
		ft_add_char_to_buff(data, (unsigned char)(0x80 | ((c >> 12) & 0x3F)));
		ft_add_char_to_buff(data, (unsigned char)(0x80 | ((c >> 6) & 0x3F)));
		ft_add_char_to_buff(data, (unsigned char)(0x80 | (c & 0x3F)));
	}
}

void		ft_process_str(t_printf *data)
{
	if (data->var == NULL)
		return ;
	data->var_len = ft_strlen(data->var);
	if ((data->precision >= 0 && data->precision < data->var_len))
	{
		data->var[data->precision] = '\0';
		data->var_len = ft_strlen(data->var);
	}
	if (data->width > data->var_len)
		ft_put_width(data);
	ft_add_str_to_buff(data, data->var);
}

static void	ft_wstr2(t_printf *data)
{
	wchar_t *c;

	if (!GET_BIT(5))
	{
		data->width > data->var_len ? ft_put_width(data) : 0;
		ft_add_str_to_buff(data, data->var);
		c = data->wstr;
		while (*c != L'\0')
			ft_wcs_to_buff(data, *c++);
	}
	else
	{
		c = data->wstr;
		while (*c != L'\0')
			ft_wcs_to_buff(data, *c++);
		data->width > data->var_len ? ft_put_width(data) : 0;
		ft_add_str_to_buff(data, data->var);
	}
	ft_wstrdel(&data->wstr);
}

void		ft_process_wstr(t_printf *data)
{
	int	p;
	int	x;
	int	z;

	p = 0;
	x = 0;
	if (data->wstr == NULL)
		return ;
	data->var_len = ft_wcslen(data->wstr);
	if ((data->precision >= 0 && data->precision < data->var_len))
	{
		z = ft_wcharlen(data->wstr[x]);
		while (p + z <= data->precision)
		{
			p += z;
			z = ft_wcharlen(data->wstr[++x]);
		}
		data->wstr[x] = L'\0';
		data->var_len = ft_wcslen(data->wstr);
	}
	ft_wstr2(data);
}
