/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:53:28 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/14 19:24:50 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putwcstr(wchar_t *str)
{
	int len;

	len = 0;
	while (*str != L'\0')
	{
		len += ft_putwchar(*str);
		str++;
	}
	return (len);
}
