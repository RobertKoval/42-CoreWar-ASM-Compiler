/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:33:47 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/18 11:35:09 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	s = (char*)str;
	dup = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (0);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

wchar_t	*ft_wstrdup(const wchar_t *str)
{
	wchar_t	*s;
	wchar_t	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	s = (wchar_t*)str;
	dup = (wchar_t*)malloc(sizeof(wchar_t) * ft_wcslen(s) + sizeof(L"\0"));
	if (!dup)
		return (0);
	while (*s != L'\0')
	{
		*dup++ = *s++;
		i++;
	}
	*dup = L'\0';
	return (dup - i);
}
