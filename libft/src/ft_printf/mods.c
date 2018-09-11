/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 00:04:56 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/20 22:43:48 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_color(t_printf *data)
{
	ft_flush_buffer(data);
	if (ft_strstr(data->tmplt, "{red}"))
		ft_printf(RED);
	else if (ft_strstr(data->tmplt, "{grn}"))
		ft_printf(GRN);
	else if (ft_strstr(data->tmplt, "{yel}"))
		ft_printf(YEL);
	else if (ft_strstr(data->tmplt, "{blu}"))
		ft_printf(BLU);
	else if (ft_strstr(data->tmplt, "{mag}"))
		ft_printf(MAG);
	else if (ft_strstr(data->tmplt, "{cyn}"))
		ft_printf(CYN);
	else if (ft_strstr(data->tmplt, "{wht}"))
		ft_printf(WHT);
	else if (ft_strstr(data->tmplt, "{eoc}"))
		ft_printf(RESET);
}

inline void	ft_mods(t_printf *data)
{
	if (ft_strstr(data->tmplt, "{err}"))
		data->fd = 2;
	else if (ft_strstr(data->tmplt, "{file}"))
		data->fd = va_arg(*(data)->arg, int);
	else
		ft_print_color(data);
}
