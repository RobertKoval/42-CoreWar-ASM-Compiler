/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:38:06 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/21 18:29:07 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *a)
{
	char	p;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	if (a && (len = ft_strlen(a)) != 0)
	{
		end = len - 1;
		while (start < end)
		{
			p = a[start];
			a[start] = a[end];
			a[end] = p;
			start++;
			end--;
		}
	}
}
