/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:17:20 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/21 13:48:25 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*cs;
	size_t	i;
	size_t	size;

	size = len + 1;
	str = NULL;
	i = 0;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * size + sizeof('\0'));
		if (str)
		{
			cs = str;
			while (size-- > 0)
				*cs++ = '\0';
			while (i < len)
				str[i++] = s[start++];
			str[i] = '\0';
			return (str);
		}
	}
	return (str);
}
