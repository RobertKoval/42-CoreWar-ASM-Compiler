/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_fix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:29:03 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/11 22:33:36 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_token	*ft_get_labeled_operation(t_application *app, char *label, int id)
{
	t_token	*l;
	char	*tmp;

	if (!(l = app->tokens) || !label)
		return (NULL);
	while (l)
	{
		if (l->type_of_token == TT_LABEL)
		{
			tmp = ft_strsub(l->cur_str, 0, l->cur_str_len - 1);
			if ((l->type_of_token == TT_LABEL) && (ft_strcmp(label, tmp) == 0))
				while (l)
				{
					if (l->type_of_token == TT_OPCODE)
					{
						ft_strdel(&tmp);
						return (l);
					}
					l = l->next;
				}
			ft_strdel(&tmp);
		}
		if (l)
			l = l->next;
	}
	return (NULL);
}

t_token	*ft_get_parent_operation(t_token *t)
{
	if (t == NULL)
		return (NULL);
	while (t)
	{
		if (t->type_of_token == TT_OPCODE)
			return (t);
		t = t->prev;
	}
}

int 	ft_bytes_between(t_token *a, t_token *b)
{
	int bytes;

	bytes = 0;
	while (a && a->id != b->id)
	{
		if (a->arg_size == AS_ONE)
			bytes += 1;
		else if (a->arg_size == AS_TWO)
			bytes += 2;
		else if (a->arg_size == AS_FOUR)
			bytes += 4;
		a = a->next;
	}
	return (bytes);
}

int 	ft_get_distance(t_application *app, t_token *s)
{
	t_token *lbl_trgt;
	t_token	*lbl_strt;

	if (s->arg_type == AT_DIRECT_LABEL)
		lbl_trgt = ft_get_labeled_operation(app, s->cur_str + 2, s->id);
	else
		lbl_trgt = ft_get_labeled_operation(app, s->cur_str + 1, s->id);
	lbl_strt = ft_get_parent_operation(s);
	if (lbl_trgt == NULL) /// no code after label
		return (0);
	if (lbl_strt->id < lbl_trgt->id)
		return (ft_bytes_between(lbl_strt, lbl_trgt));
	else if (lbl_strt->id > lbl_trgt->id)
		return ((-1) * ft_bytes_between(lbl_trgt, lbl_strt));
	return (0);
}

void	ft_check_label_code(t_application *app)
{
	t_token *s;

	s = app->tokens;
	while (s)
	{
		if (s->type_of_token == TT_ARGUMENT &&
				(s->arg_type == AT_DIRECT_LABEL ||
					s->arg_type == AT_INDIRECT_LABEL))
		{
			if (s->arg_size == AS_TWO)
				s->two_b_val = ft_get_distance(app, s);
			else if (s->arg_size == AS_FOUR)
				s->four_b_val = ft_get_distance(app, s);
		}
		s = s->next;
	}
}

