/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:33:47 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/26 17:56:45 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locate a substring in a string
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*str;
	size_t			len;

	str = (unsigned char*)haystack;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	while (*str != '\0' && needle)
	{
		if (ft_strncmp((char*)str, needle, len) == 0)
			return ((char*)str);
		str++;
	}
	return (0);
}
