/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:32:38 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/21 14:05:14 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*cs;

	str = (char*)malloc(sizeof(char) * size + sizeof('\0'));
	if (!str)
		return (NULL);
	cs = str;
	cs[size] = '\0';
	while (size-- > 0)
		*cs++ = '\0';
	return (str);
}
