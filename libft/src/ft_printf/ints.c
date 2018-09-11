/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 22:08:40 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/21 19:00:11 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_int(t_printf *data)
{
	if (data->did < 0)
		RM_BIT(4);
	if (GET_BIT(2) && !GET_BIT(4))
		data->width--;
	else if (GET_BIT(4))
		data->width--;
	if (data->did == 0)
		data->precision == 0 ? data->var[0] = '\0' : 0;
	else if ((data->did < 0) && (data->minus = 1) && data->width--)
		ft_strcpy(data->var, data->var + 1) ? RM_BIT(4) : 0;
	data->var_len = ft_strlen(data->var);
	if (data->precision > data->var_len)
		ft_padding_xou(data, 3, '0');
	if (data->width > data->var_len)
		ft_put_width(data);
	else if (data->minus || GET_BIT(4))
		ft_add_hash(data);
	if (GET_BIT(2) && !(GET_BIT(4)) && data->did >= 0)
		ft_strprepend(&data->var, " ");
	ft_add_str_to_buff(data, data->var);
}

void	ft_process_xou(t_printf *data)
{
	if (data->xou == 0)
	{
		(GET_BIT(17) || ((GET_BIT(19)) && data->precision == 0)) ? 0
															: RM_BIT(1);
		data->precision == 0 ? data->var[0] = '\0' : 0;
		data->var_len = ft_strlen(data->var);
	}
	if (GET_BIT(1))
	{
		if (GET_BIT(21) || GET_BIT(22))
			data->width -= 2;
		else if (GET_BIT(19))
		{
			data->width--;
			data->precision--;
		}
	}
	if (data->precision > data->var_len)
		ft_padding_xou(data, 3, '0');
	if (data->width > data->var_len)
		ft_put_width(data);
	else
		GET_BIT(1) ? ft_add_hash(data) : 0;
	ft_add_str_to_buff(data, data->var);
}
