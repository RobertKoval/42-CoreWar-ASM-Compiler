/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validate_token2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:03:35 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/15 16:44:32 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int 	ft_valid_direct_label(const char *str)
{
	int i;

	if (str[0] && str[1] && str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
	{
		if (ft_strlen(str + 2) > 0)
		{
			i = 2;
			while (str[i])
			{
				if (!ft_strchr(LABEL_CHARS, str[i]))
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}

int 	ft_valid_indirect_label(const char *str)
{
	size_t i;

	i = 1;
	if (str)
	{
		if (str[i] && str[0] == LABEL_CHAR)
		{
			while (str[i])
			{
				if (!ft_strchr(LABEL_CHARS, str[i]))
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}

int 	ft_valid_direct_int(const char *str)
{
	int i;

	if (str[0] == DIRECT_CHAR)
	{
		i = 1;
		while (str[i])
		{
			if (!ft_isdigit(str[i]) && str[i] != '-')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int 	ft_valid_indirect_int(const char *str)
{
	int i;

	i = 0;
	if (str[0] != '-' && !ft_isdigit(str[0]))
		return (i);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (i);
}

int 	ft_valid_registr(const char *str, t_token *a)
{
	int r;

	if (str && str[0] == 'r')
	{
		if (ft_valid_indirect_int(str + 1))
		{
			r = ft_atoi(str + 1);
			if (r >= 1 && r <= REG_NUMBER)
				return (r);
			else
			{
				ft_error(ET_UNEXIST_REGISTR, a); // TODO (3) write error
			}
		}
	}
	return (0);
}