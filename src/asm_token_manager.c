/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:53:37 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/19 15:15:13 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_token	*ft_init_token(void)
{
	t_token *tok;

	if (!(tok = malloc(sizeof(t_token))))
		ft_error(ET_UNDEFINED_ERROR, NULL);
	*tok = (t_token){.in_file = NULL};
	return (tok);
}

static void		ft_token2(t_application *app, const char *str, size_t col,
		int id)
{
	app->tokens = ft_init_token();
	app->last_token = app->tokens;
	app->last_token->id = id;
	app->last_token->in_file = ft_strdup(app->line);
	app->last_token->cur_str = ft_strdup(str);
	app->last_token->cur_str_len = ft_strlen(str);
	app->last_token->cur_pos[0] = app->row;
	app->last_token->cur_pos[1] = col;
	app->last_token->next = NULL;
	app->last_token->prev = NULL;
}

t_token			*ft_save_token(t_application *app, const char *str, size_t col)
{
	static int id;

	if (!id)
		id = 1;
	if (!app->last_token)
		ft_token2(app, str, col, id);
	else
	{
		app->last_token->next = ft_init_token();
		app->last_token->next->prev = app->last_token;
		app->last_token = app->last_token->next;
		app->last_token->id = id;
		app->last_token->in_file = ft_strdup(app->line);
		app->last_token->cur_str = ft_strdup(str);
		app->last_token->cur_str_len = ft_strlen(str);
		app->last_token->cur_pos[0] = app->row;
		app->last_token->cur_pos[1] = col;
		app->last_token->next = NULL;
	}
	id++;
	return (app->last_token);
}
