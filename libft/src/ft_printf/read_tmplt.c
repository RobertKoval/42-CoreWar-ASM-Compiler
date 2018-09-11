/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tmplt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 08:54:50 by rkoval            #+#    #+#             */
/*   Updated: 2018/06/05 08:54:53 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_save_bitspecifier(t_printf *data)
{
	int i;

	i = data->tmplt_len - 1;
	if (ft_strchr("DOUCS", data->tmplt[i]))
		SET_BIT(12);
	if (CMPR(i, 's') || CMPR(i, 'S'))
		SET_BIT(16);
	else if (CMPR(i, 'p'))
		SET_BIT(17);
	else if (CMPR(i, 'i') || CMPR(i, 'd') || CMPR(i, 'D'))
		SET_BIT(18);
	else if (data->tmplt[i] == 'o' || data->tmplt[i] == 'O')
		SET_BIT(19);
	else if (data->tmplt[i] == 'u' || data->tmplt[i] == 'U')
		SET_BIT(20);
	else if (data->tmplt[i] == 'x')
		SET_BIT(21);
	else if (data->tmplt[i] == 'X')
		SET_BIT(22);
	else if (data->tmplt[i] == 'c' || data->tmplt[i] == 'C')
		SET_BIT(23);
	else if (data->tmplt[i] == '%')
		SET_BIT(28);
	else if (data->tmplt[i] == 'b')
		SET_BIT(24);
}

void		ft_save_bitflags(t_printf *data)
{
	int i;

	i = 0;
	while (i < data->tmplt_len)
	{
		if (data->tmplt[i] == '#')
			SET_BIT(1);
		else if (data->tmplt[i] == ' ')
			SET_BIT(2);
		else if ((i == 0 && data->tmplt[i] == '0') || (i - 1 >= 0 &&
					(data->tmplt[i] == '0' && data->tmplt[i - 1] != '0')))
		{
			i == 0 ? SET_BIT(3) : 0;
			if (i - 1 >= 0 && !(data->tmplt[i - 1] >= '1'
									&& data->tmplt[i - 1] <= '9') &&
					data->tmplt[i - 1] != '.')
				SET_BIT(3);
		}
		else if (data->tmplt[i] == '+')
			SET_BIT(4);
		else if (data->tmplt[i] == '-')
			SET_BIT(5);
		i++;
	}
}

static void	ft_lenp2(t_printf *data, const char *s, int *i, int *x)
{
	char *d;

	if (s[*i] == '*' && s[*i - 1] == '.')
		data->precision = va_arg((*(data)->arg), int);
	else if (s[*i] == '.' && (s[*i + 1] <= '0' || s[*i + 1] > '9')
			&& s[*i + 1] != '*' && (data->precision = 0))
		;
	else if (s[*i] >= '1' && s[*i] <= '9')
	{
		while ((s[*i + *x] >= '0' && s[*i + *x] <= '9'))
			(*x)++;
		if (*i - 1 >= 0 && s[*i - 1] == '.')
		{
			d = ft_strsub(data->tmplt, *i, *x);
			data->precision = ft_atoi((d));
		}
		else
		{
			d = ft_strsub(data->tmplt, *i, *x);
			data->width = ft_atoi((d));
		}
		free(d);
		*i += *x - 1;
	}
}

void		ft_len(t_printf *data)
{
	int		i;
	int		x;
	char	*s;

	i = 0;
	s = data->tmplt;
	while (i < data->tmplt_len)
	{
		x = 0;
		while (i < data->tmplt_len)
		{
			if ((s[i] >= '1' && s[i] <= '9') || CMPR(i, '.') || CMPR(i, '*'))
				break ;
			i++;
		}
		if (i < data->tmplt_len && s[i] == '*' && s[i - 1] != '.')
		{
			data->width = va_arg((*(data)->arg), int);
			data->width < 0 && (data->width *= -1) ? SET_BIT(5) : 0;
		}
		else if (i < data->tmplt_len)
			ft_lenp2(data, s, &i, &x);
		i++;
	}
}

void		ft_save_bitlength(t_printf *data)
{
	int i;

	i = data->tmplt_len - 1;
	if (i >= 1 && data->tmplt[i - 1] == 'z')
		SET_BIT(9);
	else if (i >= 1 && data->tmplt[i - 1] == 'j')
		SET_BIT(10);
	else if (i >= 2 && data->tmplt[i - 1] == 'l' && data->tmplt[i - 2] == 'l')
		SET_BIT(11);
	else if (i >= 1 && (data->tmplt[i - 1] == 'l' || data->tmplt[i] == 'D'
							|| data->tmplt[i] == 'O' || data->tmplt[i] == 'U'))
		SET_BIT(12);
	else if (i >= 1 && data->tmplt[i - 1] == 'h' && data->tmplt[i - 2] != 'h')
		SET_BIT(13);
	else if ((i >= 2 && data->tmplt[i - 1] == 'h'
			&& data->tmplt[i - 2] == 'h'))
		SET_BIT(14);
}
