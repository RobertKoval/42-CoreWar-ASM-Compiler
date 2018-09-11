/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:45:00 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/21 18:03:31 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strprepend(char **base, char *src)
{
	char	*tmp;
	size_t	len;

	if (!*base)
		len = ft_strlen(src);
	if (*base && src)
	{
		tmp = ft_strjoin(src, *base);
		ft_strdel(base);
		*base = tmp;
	}
	else
	{
		tmp = ft_strnew(len);
		tmp = ft_strncpy(tmp, src, len);
		*base = tmp;
	}
}
