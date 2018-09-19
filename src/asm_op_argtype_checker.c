/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_argtype_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:31:45 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/19 15:23:54 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	Check if arguments has valid type
*/

static void	ft_calculate_args2(t_token *t, int op, size_t arg_n)
{
	if (t->arg_type == AT_INDIRECT_LABEL || t->arg_type == AT_INDIRECT_INT)
	{
		if (!(T_IND & g_op_tab[op].args[arg_n]))
			ft_error(ET_INVALID_ARGTYPE, t);
	}
	else if (t->arg_type == AT_DIRECT_LABEL || t->arg_type == AT_DIRECT_INT)
	{
		if (!(T_DIR & g_op_tab[op].args[arg_n]))
			ft_error(ET_INVALID_ARGTYPE, t);
	}
}

static void	ft_calculate_args(t_token *t)
{
	size_t	arg_n;
	int		op;

	arg_n = 0;
	if ((op = ft_get_opcode(t->cur_str)) == -1)
		ft_error(ET_UNDEFINED, NULL);
	else if (!(t = t->next))
		ft_error(ET_UNDEFINED, NULL);
	while (t && (t->type_of_token == TT_ARGUMENT ||
	t->type_of_token == TT_SEPARATE_CHAR))
	{
		if (t->type_of_token == TT_ARGUMENT)
		{
			if (t->arg_type == AT_REGISTR)
			{
				if (!(T_REG & g_op_tab[op].args[arg_n]))
					ft_error(ET_INVALID_ARGTYPE, t);
			}
			else
				ft_calculate_args2(t, op, arg_n);
			arg_n++;
		}
		t = t->next;
	}
}

void		ft_check_argtypes(t_token *t)
{
	if (!t)
		ft_error(ET_UNDEFINED, NULL);
	while (t)
	{
		if (t->type_of_token == TT_OPCODE)
			ft_calculate_args(t);
		t = t->next;
	}
}
