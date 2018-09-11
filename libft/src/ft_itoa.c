/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:09:19 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 14:46:43 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(intmax_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_strnew(ft_digilen(n));
	if (!str)
		return (NULL);
	if (n == MIN_INT64)
	{
		ft_strcpy(str, "-9223372036854775808");
		return (str);
	}
	else if (n < 0)
	{
		str[ft_digilen(n) - 1] = '-';
		n *= -1;
	}
	while (n / 10 > 0)
	{
		str[i++] = (n % 10 + '0');
		n /= 10;
	}
	str[i] = (n % 10 + '0');
	ft_strrev(str);
	return (str);
}

char	*ft_uitoa(uintmax_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_strnew((size_t)ft_udigilen(n));
	if (!str)
		return (NULL);
	while (n / 10 > 0)
	{
		str[i++] = (char)(n % 10 + '0');
		n /= 10;
	}
	str[i] = (char)(n % 10 + '0');
	ft_strrev(str);
	return (str);
}
