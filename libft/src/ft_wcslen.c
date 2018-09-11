/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:49:48 by rkoval            #+#    #+#             */
/*   Updated: 2018/03/21 23:30:46 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_wcslen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str != L'\0')
	{
		len += ft_wcharlen(*str);
		++str;
	}
	return (len);
}
