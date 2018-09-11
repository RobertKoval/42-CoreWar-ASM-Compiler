/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:48:12 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/20 12:14:14 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_sten(char const *str)
{
	int		*array;
	size_t	s;
	size_t	e;

	array = (int*)malloc(sizeof(int) * 2);
	if (!array)
		return (NULL);
	s = 0;
	e = ft_strlen(str) - 1;
	while (str[s] == ' ' || str[s] == ',' || str[s] == '\n' || str[s] == '\t')
		s++;
	array[0] = s;
	while (str[e] == ' ' || str[e] == ',' || str[e] == '\n' || str[e] == '\t')
		e--;
	array[1] = e + 1;
	return (array);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		*arr;

	str = NULL;
	arr = NULL;
	if (s)
	{
		arr = ft_sten(s);
		if (!arr)
			return (NULL);
		if (arr[1] == 0)
			str = ft_strnew(0);
		else
			str = ft_strsub(s, arr[0], arr[1] - arr[0]);
	}
	return (str);
}
