/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_description_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:16:57 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/20 18:37:09 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_remove_next_token(t_token *main)
{
	t_token *del;
	t_token *next;

	del = main->next;
	next = main->next->next;
	ft_strdel(&del->cur_str);
	ft_strdel(&del->in_file);
	main->next = next;
	free(del);
}

static void	ft_desc_mod2(t_token *start, t_token *po)
{
	char *tmp;

	tmp = ft_strjoin(start->cur_str, "\n");
	ft_strdel(&start->cur_str);
	start->cur_str = tmp;
	tmp = ft_strjoin(start->cur_str, po->cur_str);
	ft_strdel(&start->cur_str);
	start->cur_str = tmp;
	ft_remove_next_token(start);
}

void		ft_description_mod(t_token *start)
{
	t_token *po;
	char *tmp;

	if (start->cur_str[start->cur_str_len - 1] == '"' && start->cur_str_len -
	1 != 0)
		start->type_of_token = TT_STRING;
	else
	{
		po = start->next;
		while (po && po->cur_str[po->cur_str_len - 1] != '"')
		{
			tmp = ft_strjoin(start->cur_str, "\n");
			ft_strdel(&start->cur_str);
			start->cur_str = tmp;
			tmp = ft_strjoin(start->cur_str, po->cur_str);
			ft_strdel(&start->cur_str);
			start->cur_str = tmp;
			ft_remove_next_token(start);
			po = start->next;
		}
		if (po && po->cur_str[po->cur_str_len - 1] == '"')
			ft_desc_mod2(start, po);
		start->cur_str_len = ft_strlen(start->cur_str);
		start->type_of_token = TT_STRING;
	}
}