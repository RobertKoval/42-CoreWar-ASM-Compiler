/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_code_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:14:13 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/15 13:50:43 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void ft_check_name(t_application *app, t_token *a)
{
	if (!app->state.app_name)
		app->state.app_name = 1;
	else if (app->state.app_name)
		ft_error(ET_NAME_AGAIN, a);
	if (!a->next || a->next->type_of_token != TT_STRING)
		ft_error(ET_NAME_NO_STRING, a);
	else if (a->next->cur_str_len <= 2)
		ft_error(ET_NAME_TO_SHORT, a);
	else if (a->next->cur_str_len > PROG_NAME_LENGTH)
		ft_error(ET_NAME_TO_LONG, a);
	else if (a->id != 1)
	{
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Name must be in first "
						  "line\n", a->cur_pos[0], a->cur_pos[1]);
		exit(1);
	}
}

static void ft_check_desc(t_application *app, t_token *a)
{
	if (!app->state.app_desc)
		app->state.app_desc = 1;
	else if (app->state.app_desc)
		ft_error(ET_DESC_AGAIN, a);
	if (!a->next || a->next->type_of_token != TT_STRING)
		ft_error(ET_DESC_NO_STRING, a);
//	else if (a->next->cur_str_len <= 2)
//		ft_error(ET_DESC_TO_SHORT, a);
	else if (a->next->cur_str_len > COMMENT_LENGTH)
		ft_error(ET_DESC_TO_LONG, a);
	else if (a->id != 3)
	{
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Description "
			"must after name \n", a->cur_pos[0], a->cur_pos[1]);
		exit(1);
	}
}

static void ft_check_label(t_application *app, t_token *a)
{
	t_token *b;

	if (a->cur_str_len < 2)
		ft_error(ET_LABEL_TO_SHORT, a);
	else if (ft_strchr(a->cur_str, LABEL_CHAR) != ft_strrchr(a->cur_str, LABEL_CHAR))
		ft_error(ET_LABEL_MANY_CHARS, a);
	//////!!!///////// It's valid :( FUUU
	//else if (a->next->type_of_token == TT_LABEL)
		//ft_error(ET_LABEL_MANY_LABELS_ROW, a);
	b = app->tokens;
	while (b)
	{
		if (a != b && ft_strcmp(a->cur_str, b->cur_str) == 0)
			ft_error(ET_LABEL_DUPLICATE, a);
		b = b->next;
	}
}


/*
 * Check tokens if they have valid structure
 */
void	ft_check_source_structure(t_application *app)
{
	t_token *a;

	a = app->tokens;
	while (a)
	{
		if (a->type_of_token == TT_NAME)
			ft_check_name(app, a);
		else if (a->type_of_token == TT_COMMENT)
			ft_check_desc(app, a);
		else if (a->type_of_token == TT_UNDEFINED)
			ft_error(ET_UNDEFINED_ERROR, a);
		else if (a->type_of_token == TT_STRING && a->next && a->next->type_of_token == TT_STRING)
			ft_error(ET_UNDEFINED_STRING, a);
		else if (a->type_of_token == TT_LABEL)
			ft_check_label(app, a);
		else if (a->type_of_token == TT_OPCODE)
			ft_check_operation(a);
		a = a->next;
	}
	if (!app->state.app_name)
		ft_error(ET_NO_NAME_CMD, NULL);
	else if (!app->state.app_desc)
		ft_error(ET_NO_COMMENT_CMD, NULL);
}