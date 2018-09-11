/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:33:47 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/16 19:24:56 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == '\0')
			return (i + 1);
		if (str[i + 2] == '\0')
			return (i + 2);
		if (str[i + 3] == '\0')
			return (i + 3);
		if (str[i + 4] == '\0')
			return (i + 4);
		if (str[i + 5] == '\0')
			return (i + 5);
		i += 5;
	}
	return (i);
}
