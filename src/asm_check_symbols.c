/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:26:56 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/19 15:28:27 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_send_bad_char(t_token *tok, char c)
{
	ft_printf("%{err}Lexical error at [%03zu:%03zu] Bad symbol '%c'\n"
				"%s\n", tok->cur_pos[0], tok->cur_pos[1], c, tok->in_file);
	exit(1);
}

void		ft_check_symbols(t_token *a)
{
	size_t	i;
	char	c;

	i = 0;
	if (!a || a->type_of_token == TT_STRING || a->type_of_token == TT_COMMENT ||
			a->type_of_token == TT_NAME)
		return ;
	while (a->cur_str[i])
	{
		c = a->cur_str[i];
		if (!ft_isspace(c) && !ft_isalnum(c) && c != ',')
		{
			if (a->type_of_token == TT_LABEL && c != '_' && c != ':' && c !=
			'%' &&
								a->cur_str[a->cur_str_len - 1] != ':')
				ft_send_bad_char(a, c);
		}
		i++;
	}
}
