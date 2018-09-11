/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:44:45 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/21 18:04:06 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strappend(char **base, char *src)
{
	char	*tmp;
	size_t	len;

	if (!*base)
		len = ft_strlen(src);
	if (*base)
	{
		tmp = ft_strjoin(*base, src);
		free(*base);
		*base = tmp;
	}
	else
	{
		tmp = ft_strnew(len);
		tmp = ft_strncpy(tmp, src, len);
		*base = tmp;
	}
}
