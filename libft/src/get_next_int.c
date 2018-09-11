/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:32:50 by rkoval            #+#    #+#             */
/*   Updated: 2018/07/03 20:42:25 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_fucking_norme(int *val, char *po)
{
	if (val == 0)
		*val = *po - '0';
	else
	{
		*val *= 10;
		*val += *po - '0';
	}
}

int			get_next_int(char **src)
{
	int		val;
	int		minus;
	char	*po;

	val = 0;
	minus = 0;
	if (!src || !*src || !**src || ft_strlen(*src) > 9)
		return (0);
	po = *src;
	while (*po && (*po < '0' || *po > '9') && *po != '-')
		po++;
	if (*po == '-')
	{
		minus = 1;
		po++;
	}
	while (*po >= '0' && *po <= '9')
	{
		ft_fucking_norme(&val, po);
		po++;
	}
	*src = po;
	return (minus ? -(val) : val);
}
