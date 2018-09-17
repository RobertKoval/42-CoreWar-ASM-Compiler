/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_utillity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:59:36 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/09 20:59:36 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int 	ft_to_big_endian(int n)   // TODO (7) how it works ?
{
	int nv;
	nv = (((n << 8) & 0xFF00FF00) | ((n >> 8) & 0xFF00FF));
	return ((nv << 16) | ((nv >> 16) & 0xFFFF));
}

short 	ft_to_big_sendian(short n)
{
	return ((n << 8) | ((n >> 8) & 0xFF));
}

size_t 	ft_skip_spaces(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		return (i);
	return (0);
}

/*
 * Get operation index
 */
int 	ft_get_opcode(const char *str)
{
	int i;

	i = 0;
	while (g_op_tab[i].instruct)
	{
		if (ft_strcmp(g_op_tab[i].instruct, str) == 0)
			return (i);
		i++;
	}
	return (-1);
}