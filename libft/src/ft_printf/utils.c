/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 22:10:27 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 14:40:17 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_add_hash(t_printf *data)
{
	if (GET_BIT(21) || GET_BIT(17))
		ft_strprepend(&data->var, "0x");
	else if (GET_BIT(22))
		ft_strprepend(&data->var, "0X");
	else if (GET_BIT(19))
		ft_strprepend(&data->var, "0");
	else if (data->did >= 0 && GET_BIT(4) && GET_BIT(18))
		ft_strprepend(&data->var, "+");
	else if (data->minus == 1)
		ft_strprepend(&data->var, "-");
}

void	ft_padding_xou(t_printf *data, int a, char c)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	if (a == 1 || a == 2)
		len = data->width - data->var_len;
	else
		len = data->precision - data->var_len;
	tmp = ft_strnew(len);
	while (i < len)
		tmp[i++] = c;
	a != 2 ? ft_strprepend(&data->var, tmp) : ft_strappend(&data->var, tmp);
	data->var_len = ft_strlen(data->var);
	if (tmp)
		free(tmp);
}

void	ft_put_width(t_printf *data)
{
	if (GET_BIT(3))
	{
		ft_padding_xou(data, 1, '0');
		if (data->var && !(data->var[0] == '0' && data->var[1] == '\0')
			&& (GET_BIT(1) || GET_BIT(4) || data->minus))
			ft_add_hash(data);
	}
	else
	{
		if (GET_BIT(1) || GET_BIT(4) || data->minus)
			ft_add_hash(data);
		GET_BIT(5) ? ft_padding_xou(data, 2, ' ') :
		ft_padding_xou(data, 1, ' ');
	}
}

void	ft_repair_flags(t_printf *data)
{
	if (GET_BIT(3))
	{
		if (GET_BIT(5))
			RM_BIT(3);
		else if (data->precision >= 0 && (GET_BIT(18) ||
										GET_BIT(19) || GET_BIT(20) ||
										GET_BIT(21) || GET_BIT(22)))
			RM_BIT(3);
	}
	if (GET_BIT(4))
	{
		if (!(GET_BIT(18)))
			RM_BIT(4);
		else if (GET_BIT(2))
		{
			RM_BIT(3);
			RM_BIT(2);
		}
	}
	if (MB_CUR_MAX == 1 && GET_BIT(23))
		RM_BIT(12);
}

void	ft_clear_data(t_printf *data)
{
	if (data->tmplt)
	{
		free(data->tmplt);
		data->tmplt = NULL;
	}
	if (data->var)
	{
		free(data->var);
		data->var = NULL;
	}
	data->tmplt_len = 0;
	data->width = -1;
	data->precision = -1;
	data->flags = 0;
	data->minus = 0;
}
