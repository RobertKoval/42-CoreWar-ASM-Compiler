/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:02:28 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/20 12:15:50 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(const char *s, char d)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] != d)
			{
				count++;
				while (s[i] != d && s[i] != '\0')
					i++;
			}
			while ((s[i] == d) && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**array;
	unsigned int	w_len;
	size_t			i;
	unsigned int	s_ptr;
	size_t			w_con;

	w_con = ft_wcount((char*)s, c);
	i = 0;
	s_ptr = 0;
	array = (char**)malloc(sizeof(char*) * w_con + 8);
	if (!array)
		return (NULL);
	while (i < w_con)
	{
		w_len = 0;
		while (s[s_ptr] == c && s[s_ptr] != '\0')
			s_ptr++;
		while (s[s_ptr + w_len] != c && s[s_ptr + w_len] != '\0')
			w_len++;
		array[i++] = ft_strsub(s, s_ptr, w_len);
		s_ptr += w_len + 1;
	}
	array[i] = NULL;
	return (array);
}
