/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:37:37 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/19 21:20:20 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *f_ver;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	f_ver = f(lst);
	new = f_ver;
	while (lst->next)
	{
		lst = lst->next;
		if (!(f_ver->next = f(lst)))
			return (NULL);
		f_ver = f_ver->next;
	}
	return (new);
}
