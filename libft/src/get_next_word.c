/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 21:15:37 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/03 21:15:37 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_word(char **src)
{
	size_t			i;
	unsigned int	s;
	char			*word;
	char			*po;

	i = 0;
	s = 0;
	word = NULL;
	if (!src || !*src || !**src)
		return (NULL);
	po = *src;
	while (*po && *po < 33)
	{
		s++;
		po++;
	}
	while (*po && *po > 32)
	{
		i++;
		po++;
	}
	if (i != 0)
		word = ft_strsub(*src, s, i);
	*src = po;
	return (word);
}
