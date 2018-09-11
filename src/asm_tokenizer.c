/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:45:30 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/11 13:26:02 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_check_string_tokens(t_application *app)
{
	t_token	*a;
	//char *tmp;
	a = app->tokens;
	while (a)
	{
//		if (a->type_of_token == TT_NAME)   // save name ? remove it
//		{
//			if (a->next->type_of_token == TT_STRING)
//			{
//				tmp = ft_strsub(a->next->cur_str, 1,
//													a->next->cur_str_len - 2);
//				app->state.name = ft_strjoin(tmp, ".cor");
//				ft_strdel(&tmp);
//			}
//		}
		if (a->type_of_token == TT_STRING && a->cur_str[a->cur_str_len - 1]
											 != '"')
			ft_error(ET_NO_QUOTES, a);
		a = a->next;
	}
}




static void	ft_recognize_tokens(t_application *app)
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
			a->type_of_token = TT_STRING;
		else if (ft_valid_label(a->cur_str))
			a->type_of_token = TT_LABEL;
		else if (ft_valid_opcode(a->cur_str))
			a->type_of_token = TT_OPCODE;
		else if (ft_valid_argument(a->cur_str))
			a->type_of_token = TT_ARGUMENT;
		else if (a->cur_str_len == 1 && a->cur_str[0] == SEPARATOR_CHAR)
			a->type_of_token = TT_SEPARATE_CHAR;
		ft_check_symbols(a);
		a = a->next;
	}
	ft_check_string_tokens(app);
	ft_check_source_structure(app);
}


static void	slice_p2(const char *str, size_t i, size_t *k)
{
	if (str[i] == '"')
	{
		while (str[*k] && str[*k] != '"')
			(*k)++;
		if (str[*k] == '"')
			(*k)++;
	}
	else if (str[i] == SEPARATOR_CHAR)
		;
	else
		while (str[*k] && str[*k] != SEPARATOR_CHAR && str[*k] > 33)
			(*k)++;
}

static void	ft_slice_string(t_application *app, const char *str)
{
	size_t	i;
	size_t	k;
	char 	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
		{
			if (str[i] == '#' || str[i] == ';')
				break ;
			k = i + 1;
			slice_p2(str, i, &k);
			tmp = ft_strsub(str, i, k - i);
			ft_save_token(app, tmp, i);
			i = k;
			ft_strdel(&tmp);
			continue ;
		}
		i++;
	}
}

void	ft_tokenizer(t_application *app)
{
	static size_t row;
	if (!app)
		ft_error(ET_UNDEFINED_ERROR, NULL);
	while (get_next_line(app->fd_input, &app->line) > 0)
	{
		++row;
		if (app->line[0] != '\0' && app->line[0] != '#')
		{
			app->row = row;
			ft_slice_string(app, app->line);
		}
		ft_strdel(&app->line);
	}
	ft_recognize_tokens(app);
	ft_check_label_code(app);
}