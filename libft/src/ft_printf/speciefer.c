/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speciefer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 10:54:53 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 14:09:31 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strtoup(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = (char)ft_toupper(str[i]);
		i++;
	}
}

void	ft_strings(t_printf *data)
{
	if (GET_BIT(12) && GET_BIT(16))
	{
		data->wstr = ft_wstrdup(va_arg(*(data->arg), wchar_t*));
		if (data->wstr == NULL)
			data->wstr = ft_wstrdup(L"(null)");
	}
	else if (GET_BIT(16))
	{
		data->var = ft_strdup(va_arg(*(data->arg), char*));
		if (data->var == NULL)
			data->var = ft_strdup("(null)");
	}
	else
		data->var = ft_uitobin(va_arg(*(data->arg), unsigned int));
}

void	ft_chars(t_printf *data)
{
	if (GET_BIT(12) && GET_BIT(23))
		data->wc = va_arg((*(data)->arg), wchar_t);
	else
	{
		GET_BIT(28) ? (data->c = '%') :
						(data->c = (unsigned char)va_arg((*(data)->arg), int));
		data->var = ft_strnew(1);
		data->var[0] = data->c;
	}
}

void	ft_xou(t_printf *data)
{
	if (GET_BIT(9))
		data->xou = va_arg((*(data)->arg), size_t);
	else if (GET_BIT(10))
		data->xou = va_arg((*(data)->arg), uintmax_t);
	else if (GET_BIT(11))
		data->xou = va_arg((*(data)->arg), unsigned long long int);
	else if (GET_BIT(12) || GET_BIT(17))
		data->xou = va_arg((*(data)->arg), unsigned long int);
	else if (GET_BIT(13))
		data->xou = (unsigned short int)va_arg((*(data)->arg), int);
	else if (GET_BIT(14))
		data->xou = (unsigned char)va_arg((*(data)->arg), int);
	else
		data->xou = va_arg((*(data)->arg), unsigned int);
	if (GET_BIT(21))
		data->var = ft_uitohex(data->xou);
	else if (GET_BIT(22))
		ft_strtoup((data->var = ft_uitohex(data->xou)));
	else if (GET_BIT(19))
		data->var = ft_uitooct(data->xou);
	else
		data->var = ft_uitoa(data->xou);
	data->var_len = ft_strlen(data->var);
}

void	ft_integers(t_printf *data)
{
	if (GET_BIT(9))
		data->did = va_arg((*(data)->arg), size_t);
	else if (GET_BIT(10))
		data->did = va_arg((*(data)->arg), uintmax_t);
	else if (GET_BIT(11))
		data->did = va_arg((*(data)->arg), long long int);
	else if (GET_BIT(12))
		data->did = va_arg((*(data)->arg), long int);
	else if (GET_BIT(13))
		data->did = (short int)va_arg((*(data)->arg), int);
	else if (GET_BIT(14))
		data->did = (char)va_arg((*(data)->arg), int);
	else
		data->did = va_arg((*(data)->arg), int);
	data->var = ft_itoa(data->did);
	data->var_len = ft_strlen(data->var);
}
