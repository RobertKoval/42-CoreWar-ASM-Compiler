/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:45:30 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/26 15:14:35 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	slice_p2(t_application *app, const char *str, size_t i, size_t *k)
{
	if (app->state.multi_row == 1)
	{
		while (str[*k] && str[*k] != '"')
			(*k)++;
		if (str[0] == '"' || str[*k] == '"')
		{
			app->state.multi_row = 0;
			(*k)++;
		}
	}
	else if (str[i] == '"')
	{
		while (str[*k] && str[*k] != '"')
			(*k)++;
		if (str[*k] == '"')
			(*k)++;
		else if (str[*k] != '"')
			app->state.multi_row = 1;
	}
	else if (str[i] == SEPARATOR_CHAR)
		;
	else
		while (str[*k] && str[*k] != SEPARATOR_CHAR && str[*k] > 33 &&
		str[*k] != ';' && str[*k] != COMMENT_CHAR)
			(*k)++;
}

static void	ft_slice_string(t_application *app, const char *str)
{
	size_t	i;
	size_t	k;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32 || str[i] == 10)
		{
			if (str[i] == COMMENT_CHAR || str[i] == ';')
				break ;
			k = i + 1;
			slice_p2(app, str, i, &k);
			tmp = ft_strsub(str, i, k - i);
			ft_save_token(app, tmp, i);
			i = k;
			ft_strdel(&tmp);
			continue ;
		}
		i++;
	}
}

void		ft_tokenizer(t_application *app)
{
	static size_t	row;
	char			*tmp;
	int				gnl;

	if (!app)
		ft_error(ET_UNDEFINED_ERROR, NULL);
	while ((gnl = get_next_line(app->fd_input, &app->line)) > 0)
	{
		++row;
		if ((app->line[0] != '\0') && app->line[0] != COMMENT_CHAR)
		{
			app->row = row;
			ft_slice_string(app, app->line);
		}
		else if (app->line[0] == '\0' && app->state.multi_row == 1)
		{
			app->row = row;
			tmp = ft_strjoin(app->last_token->cur_str, "\n");
			ft_strdel(&app->last_token->cur_str);
			app->last_token->cur_str = tmp;
		}
		ft_strdel(&app->line);
	}
	gnl == -1 ? ft_error(ET_IS_DIR, NULL) : 0;
	ft_recognize_tokens(app);
}
