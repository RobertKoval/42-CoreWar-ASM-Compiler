/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validate_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:59:03 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/11 13:43:46 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int 	ft_valid_label(const char *str)
{
	size_t i;

	i = ft_skip_spaces(str);
	if (str[i] == LABEL_CHAR)
		return (0);
	while (str[i] && strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] && str[i] == LABEL_CHAR)
		return (1);
	return (0);
}

int 	ft_valid_opcode(const char *str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)(str + ft_skip_spaces(str));
	while (g_op_tab[i].instruct)
	{
		if (ft_strcmp(tmp, g_op_tab[i].instruct) == 0)
			return (1);
		i++;
	}
	return (0);
}

int 	ft_valid_argument(char *str)
{
	if (ft_valid_registr(str))
		return (1);
	else if (ft_valid_direct_int(str))
		return (1);
	else if (ft_valid_direct_label(str))
		return (1);
	else if (ft_valid_indirect_int(str))
		return (1);
	else if (ft_valid_indirect_label(str))
		return (1);
	return (0);
}


// TODO (1) %1; -> ';' - start of comment, must be fixed, also for '#', it can be everywhere