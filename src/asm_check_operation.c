/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:11:03 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/11 21:13:52 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
 * Get operation index
 */
static int 	ft_get_opcode(const char *str)
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

/*
** Set arguments type in 8 bit representation -> XXYYZZ00 -> 1 byte
*/
static void ft_set_codage(t_token *tok, int arg, t_arg_type t)
{

	if (arg == 0)
		tok->codage = tok->codage | t << 6;
	else if (arg == 1)
		tok->codage = tok->codage | t << 4;
	else if (arg == 2)
		tok->codage = tok->codage | t << 2;
	else if (arg == 3)
		tok->codage = tok->codage | t;
}

static void ft_check_arg2(t_token *a, t_token *b, int i, int args)
{
	if (ft_valid_direct_label(b->cur_str))
	{
		ft_set_codage(a, args, T_DIR);
		b->arg_type = AT_DIRECT_LABEL;
		if (g_op_tab[i].label_size == 0)
			b->arg_size = AS_FOUR;
		else if (g_op_tab[i].label_size == 1)
			b->arg_size = AS_TWO;
	}
	else if (ft_valid_direct_int(b->cur_str))
	{
		ft_set_codage(a, args, T_DIR);
		b->arg_type = AT_DIRECT_INT;
		if (g_op_tab[i].label_size == 0)
		{
			b->four_b_val = ft_atoi(b->cur_str + 1);
			b->arg_size = AS_FOUR;
		}
		else if (g_op_tab[i].label_size == 1)
		{
			b->two_b_val = (short)ft_atoi(b->cur_str + 1);
			b->arg_size = AS_TWO;
		}
	}
}

static void ft_check_arg(t_token *a, t_token *b, int i, int args)
{
	if (ft_valid_registr(b->cur_str))
	{
		ft_set_codage(a, args, T_REG);
		b->arg_type = AT_REGISTR;
		b->arg_size = AS_ONE;
		b->one_b_val = (char)ft_atoi(b->cur_str + 1);
	}
	else if (ft_valid_indirect_int(b->cur_str))
	{
		ft_set_codage(a, args, T_IND);
		b->arg_type = AT_INDIRECT_INT;
		b->arg_size = AS_TWO;
		b->two_b_val = (short)ft_atoi(b->cur_str);
	}
	else if (ft_valid_indirect_label(b->cur_str))
	{
		ft_set_codage(a, args, T_IND);
		b->arg_type = AT_INDIRECT_LABEL;
		b->arg_size = AS_TWO;
	}
	else
		ft_check_arg2(a, b, i, args);
}



void	ft_check_operation(t_application *app, t_token *a)
{
	t_token	*b;
	int		i;
	int		args;


	if ((i = ft_get_opcode(a->cur_str)) == -1)
		ft_error(ET_UNDEFINED_ERROR, NULL);
	args = 0;
	a->ophex = g_op_tab[i].opcode;

	if (g_op_tab[i].octal == 0)
		a->arg_size = AS_ONE;
	else
		a->arg_size = AS_TWO;
	b = a->next;
	while (b && (b->type_of_token == TT_ARGUMENT || b->type_of_token == TT_SEPARATE_CHAR))
	{
		if (b->type_of_token == TT_ARGUMENT)
		{
			ft_check_arg(a, b, i, args);
			//char 	*v = &(g_op_tab[i].args[args]);

			/* check if args are valid by type (DIR, IND, REG)*/
//					if (a->codage[args] > g_op_tab[i].args[args])
//						ft_printf("Invalid  argument type\n", g_op_tab[i].args[args]);
			args++;
		}

		if (b->next && b->type_of_token == TT_ARGUMENT && b->next->type_of_token == TT_ARGUMENT)
			ft_printf("%{err} No separator char\n");
		if (b->type_of_token == TT_SEPARATE_CHAR && b->next && b->next->type_of_token == TT_SEPARATE_CHAR)
			ft_printf("%{err} Can't be more than one separator char\n");
		if (b->type_of_token == TT_SEPARATE_CHAR && b->next && b->next->type_of_token != TT_ARGUMENT)
			ft_printf("%{err} No argument after separator char\n");
		b = b->next;
	}
	if (args != g_op_tab[i].n_args)
		ft_printf("%{err} Must be %d arguments\n",g_op_tab[i].n_args);
}