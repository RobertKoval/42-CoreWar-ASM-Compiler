/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:03:27 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/10 21:57:47 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_write_zeroes(t_application *app, size_t x)
{
	char a;

	a = 0;
	while (x)
	{
		write(app->fd_output, &a, 1);
		x--;
	}
}

void	ft_write_app3(t_application *app,t_token *a, size_t *app_size)
{
	if (a->arg_size == AS_TWO)
	{
		write(app->fd_output, &a->ophex, 1);
		write(app->fd_output, &a->codage, 1);
		(*app_size) += 2;
	}
	else
	{
		write(app->fd_output, &a->ophex, 1);
		(*app_size)++;
	}
}

void	ft_write_app2(t_application *app, t_token *a, size_t *app_size)
{
	int		bi;
	short	bs;

	if (a->arg_size == AS_FOUR)
	{
		bi = ft_to_big_endian(a->four_b_val);
		write(app->fd_output, &bi, 4);
		(*app_size) += 4;
	}
	else if (a->arg_size == AS_TWO)
	{
		bs  = ft_to_big_sendian(a->two_b_val);
		write(app->fd_output, &bs, 2);
		(*app_size) += 2;
	}
	else if (a->arg_size == AS_ONE)
	{
		write(app->fd_output, &a->one_b_val, 1);
		(*app_size)++;
	}
}


void	ft_write_app(t_application *app)
{
	t_token *a;
	size_t	app_size;
	int 	big_endian;
	char 	*strings;
	int 	null;

	app_size = 0;
	a = app->tokens;
	null = 0;

	big_endian = ft_to_big_endian(COREWAR_EXEC_MAGIC);
	write(app->fd_output, &big_endian, 4);

	while (a)
	{
		if (a->type_of_token == TT_NAME)
		{
			strings = ft_strsub(a->next->cur_str, 1, a->next->cur_str_len - 2);
			write(app->fd_output, strings, (ft_strlen(strings)));
			ft_write_zeroes(app, (PROG_NAME_LENGTH - ft_strlen(strings)));
			write(app->fd_output, &null, 4);
			write(app->fd_output, &app_size, 4);
			ft_strdel(&strings);
		} //TODO (8) Розбити на функції
		else if (a->type_of_token == TT_COMMENT)
		{
			strings = ft_strsub(a->next->cur_str, 1, a->next->cur_str_len - 2);
			write(app->fd_output, strings, (ft_strlen(strings)));
			write(app->fd_output, &null, 4);
			ft_write_zeroes(app, (COMMENT_LENGTH - ft_strlen(strings)));
			ft_strdel(&strings);
		}
		else if (a->type_of_token == TT_OPCODE)
			ft_write_app3(app, a, &app_size);
		else if (a->type_of_token == TT_ARGUMENT)
			ft_write_app2(app, a, &app_size);
		a = a->next;
	}
	app_size = (size_t)ft_to_big_endian((int)app_size);
	lseek(app->fd_output, (PROG_NAME_LENGTH + sizeof(COREWAR_EXEC_MAGIC) + 4),
		  SEEK_SET);
	write(app->fd_output, &app_size,4);
}