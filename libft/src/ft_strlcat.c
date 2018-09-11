/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:13:32 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/19 20:55:55 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	p;
	size_t	t;
	char	*d;
	char	*s;

	d = dst;
	s = (char*)src;
	p = size;
	while (p-- != 0 && *d != '\0')
		d++;
	t = d - dst;
	p = size - t;
	if (p == 0)
		return (t + ft_strlen(s));
	while (*s != '\0')
	{
		if (p != 1)
		{
			*d++ = *s;
			p--;
		}
		s++;
	}
	*d = '\0';
	return (t + (s - src));
}
