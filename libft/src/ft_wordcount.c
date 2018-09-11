/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:57:02 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/19 13:30:19 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			if (ft_isalnum(s[i]))
			{
				count++;
				while (ft_isalnum(s[i]) && s[i] != '\0')
					i++;
			}
			while (!ft_isalnum(s[i]) && s[i] != '\0')
				i++;
		}
	return (count);
}
