/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:12:16 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/17 13:17:48 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*str;
	size_t			cplen;

	str = (unsigned char*)haystack;
	cplen = ft_strlen(needle);
	if (cplen == 0)
		return ((char*)haystack);
	while (*str != '\0' && needle && len-- >= cplen)
	{
		if (ft_strncmp((char*)str, needle, cplen) == 0)
			return ((char*)str);
		str++;
	}
	return (0);
}
