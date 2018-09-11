/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:36:25 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 14:20:32 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				ft_process(t_printf *data)
{
	if (GET_BIT(12) && GET_BIT(16))
		ft_process_wstr(data);
	else if (GET_BIT(16) || GET_BIT(24))
		ft_process_str(data);
	else if (GET_BIT(21) || GET_BIT(22) || GET_BIT(17))
		ft_process_xou(data);
	else if (GET_BIT(19) || GET_BIT(20))
		ft_process_xou(data);
	else if (GET_BIT(18))
		ft_process_int(data);
	else if (GET_BIT(23) && GET_BIT(12))
		ft_process_wchar(data);
	else if (GET_BIT(23) || GET_BIT(28))
		ft_process_char(data);
}

void				ft_converter(t_printf *data)
{
	int last;

	if (!(data->tmplt))
		return ;
	last = data->tmplt_len - 1;
	if (GET_BIT(23) || GET_BIT(28))
		ft_chars(data);
	else if (data->tmplt[0] == '{')
		ft_mods(data);
	else if (ft_strchr("xXoOuU", data->tmplt[last]))
		ft_xou(data);
	else if (GET_BIT(18))
		ft_integers(data);
	else if (GET_BIT(16) || GET_BIT(24))
		ft_strings(data);
	else if (GET_BIT(17))
	{
		SET_BIT(21);
		SET_BIT(1);
		ft_xou(data);
	}
}

void				ft_read_fmt(t_printf *data)
{
	while (*data->fmt != '\0')
	{
		if (*data->fmt == '%')
		{
			data->fmt++;
			ft_send_to_handler(data);
			if (data->tmplt)
			{
				ft_save_bitspecifier(data);
				ft_save_bitflags(data);
				ft_len(data);
				ft_save_bitlength(data);
				ft_repair_flags(data);
				ft_converter(data);
				ft_process(data);
				ft_clear_data(data);
			}
		}
		else
			ft_add_char_to_buff(data, *data->fmt++);
	}
	ft_flush_buffer(data);
}

int					ft_printf(const char *format, ...)
{
	va_list		args;
	t_printf	data;

	if (!format || !*format)
		return (0);
	va_start(args, format);
	data = (t_printf) {.arg = &args, .fmt = (char *)format, .fd = 1,
			.width = -1, .precision = -1};
	ft_read_fmt(&data);
	va_end(args);
	return (data.print_len);
}
