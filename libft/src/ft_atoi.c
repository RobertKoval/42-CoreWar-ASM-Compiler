/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:33:46 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/20 19:45:37 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_atoi(const char *str)
{
	size_t	result;
	size_t	minus;
	size_t	i;

	result = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(str[i]) || (str[i] == '+' &&
			(str[i + 1] >= '0' && str[i + 1] <= '9')))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result += str[i++] - '0';
		if ((str[i] >= '0' && str[i] <= '9'))
			result *= 10;
	}
	return (result * minus);
}

long long int		ft_llatoi(const char *str)
{
	long long int	result;
	size_t			minus;
	size_t			i;

	result = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(str[i]) || (str[i] == '+' &&
							(str[i + 1] >= '0' && str[i + 1] <= '9')))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result += str[i++] - '0';
		if ((str[i] >= '0' && str[i] <= '9'))
			result *= 10;
	}
	return (result * minus);
}
