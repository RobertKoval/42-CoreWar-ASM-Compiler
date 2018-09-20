/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:13:11 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/20 19:31:58 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*t;
	char	*s;
	size_t	n;

	t = dst;
	s = (char*)src;
	n = size;
	if (n)
	{
		while (n)
		{
			if ((*t = *s) == '\0')
				break ;
			t++;
			s++;
			n--;
		}
	}
	if (n == 0)
	{
		size == 0 ? 0 : (*t = '\0');
		while (*s++)
			;
	}
	return (s - src - 1);
}
