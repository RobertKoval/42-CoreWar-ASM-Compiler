/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 10:01:14 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/21 19:07:50 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Integer to binary
*/

char	*ft_uitobin(unsigned int num)
{
	char			*str;
	unsigned int	i;

	str = ft_strnew(64);
	i = 0;
	while (num && i < 64)
	{
		if (num & 1)
			str[i++] = '1';
		else
			str[i++] = '0';
		num >>= 1;
	}
	ft_strrev(str);
	return (str);
}

char	*ft_llitobin(long long int num)
{
	char			*str;
	unsigned int	i;
	int				len;

	len = 64;
	str = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	while (len)
	{
		str[i++] = (num & 1) + '0';
		num >>= 1;
		len--;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

/*
** Integer to HEX
*/

char	*ft_uitohex(uintmax_t num)
{
	char	*hex;
	size_t	i;

	hex = ft_strnew(64);
	i = 0;
	if (num == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	while (num > 0)
	{
		hex[i] = (unsigned char)"0123456789abcdef"[num % 16];
		num /= 16;
		i++;
	}
	ft_strrev(hex);
	return (hex);
}

char	*ft_uitooct(uintmax_t num)
{
	char	*hex;
	size_t	i;

	hex = ft_strnew(64);
	i = 0;
	if (num == 0)
	{
		hex[0] = '0';
		hex[1] = '\0';
		return (hex);
	}
	while (num > 0)
	{
		hex[i] = (unsigned char)"01234567"[num % 8];
		num /= 8;
		i++;
	}
	ft_strrev(hex);
	return (hex);
}
