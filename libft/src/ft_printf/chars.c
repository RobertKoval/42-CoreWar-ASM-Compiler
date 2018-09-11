/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 22:01:06 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 15:35:29 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_char(t_printf *data)
{
	data->var_len = ft_strlen(data->var);
	if (data->var[0] == '\0')
		data->var_len = 1;
	if (data->width > data->var_len)
		ft_put_width(data);
	if (GET_BIT(5) && data->c == '\0')
	{
		data->print_len++;
		ft_flush_buffer(data);
		write(1, "\0", 1);
	}
	ft_add_str_to_buff(data, data->var);
	if (!GET_BIT(5) && data->c == '\0')
	{
		data->print_len++;
		ft_flush_buffer(data);
		write(1, "\0", 1);
	}
}

void	ft_process_wchar(t_printf *data)
{
	data->var_len = ft_wcharlen(data->wc);
	if (!GET_BIT(5))
	{
		data->width > data->var_len ? ft_put_width(data) : 0;
		ft_add_str_to_buff(data, data->var);
	}
	if (data->wc == L'\0')
	{
		data->print_len++;
		ft_flush_buffer(data);
		ft_putwchar(data->wc);
	}
	else
		ft_wcs_to_buff(data, data->wc);
	if (GET_BIT(5))
	{
		data->width > data->var_len ? ft_put_width(data) : 0;
		ft_add_str_to_buff(data, data->var);
	}
}
