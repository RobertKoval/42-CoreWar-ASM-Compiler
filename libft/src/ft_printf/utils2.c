/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:35:20 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 14:03:37 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flush_buffer(t_printf *data)
{
	size_t len;

	len = ft_strlen(data->buffer);
	write(data->fd, &(data->buffer), len);
	data->print_len += len;
	ft_bzero(data->buffer, FT_PRINTF_BUFF_SIZE);
	data->buff_marker = 0;
}

void	ft_add_char_to_buff(t_printf *data, char c)
{
	if (data->buff_marker < FT_PRINTF_BUFF_SIZE)
		data->buffer[data->buff_marker++] = c;
	else
	{
		ft_flush_buffer(data);
		data->buff_marker = 0;
		data->buffer[data->buff_marker++] = c;
	}
}

void	ft_add_str_to_buff(t_printf *data, char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (data->buff_marker < FT_PRINTF_BUFF_SIZE)
			data->buffer[data->buff_marker++] = str[i++];
		else
		{
			ft_flush_buffer(data);
			data->buff_marker = 0;
			data->buffer[data->buff_marker++] = str[i++];
		}
	}
}

void	ft_send_to_handler(t_printf *data)
{
	int	i;

	i = 0;
	while (data->fmt[i] != '\0')
	{
		if (data->fmt[i] == '{')
		{
			while (data->fmt[++i] != '}')
				;
			break ;
		}
		if ((data->fmt[i] >= 'b' && data->fmt[i] <= 'x') ||
				(data->fmt[i] >= 'C' && data->fmt[i] <= 'X') ||
				data->fmt[i] == '%' || data->fmt[i] == '}')
			if (ft_strchr("sSpdDioOuUxXcCn%b}", data->fmt[i]))
				break ;
		i++;
	}
	if (data->fmt[i] != '\0')
	{
		data->tmplt = ft_strsub(data->fmt, 0, ++i);
		data->tmplt_len = i;
		data->fmt += i;
	}
}
