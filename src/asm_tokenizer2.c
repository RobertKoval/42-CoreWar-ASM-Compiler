/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokenizer2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:10:39 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/26 15:15:56 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_check_string_tokens(t_application *app)
{
	t_token	*a;

	a = app->tokens;
	while (a)
	{
		if (a->type_of_token == TT_STRING && a->cur_str[a->cur_str_len - 1]
										!= '"')
			ft_error(ET_NO_QUOTES, a);
		a = a->next;
	}
}

static void	ft_recognize_tokens2(t_application *app)
{
	t_token *a;

	a = app->tokens;
	while (a)
	{
		if (ft_strcmp(a->cur_str, NAME_CMD_STRING) == 0)
			a->type_of_token = TT_NAME;
		else if (ft_strcmp(a->cur_str, COMMENT_CMD_STRING) == 0)
			a->type_of_token = TT_COMMENT;
		else if (a->cur_str[0] == '"')
			ft_description_mod(a);
		else if (ft_valid_label(a->cur_str))
			a->type_of_token = TT_LABEL;
		else if (ft_valid_opcode(a->cur_str))
			a->type_of_token = TT_OPCODE;
		else if (ft_valid_argument(a->cur_str, a))
			a->type_of_token = TT_ARGUMENT;
		else if (a->cur_str_len == 1 && a->cur_str[0] == SEPARATOR_CHAR)
			a->type_of_token = TT_SEPARATE_CHAR;
		ft_check_symbols(a);
		a = a->next;
	}
	ft_check_string_tokens(app);
	ft_check_source_structure(app);
}

void		ft_recognize_tokens(t_application *app)
{
	ft_recognize_tokens2(app);
	ft_check_label_code(app);
	ft_check_argtypes(app->tokens);
}
