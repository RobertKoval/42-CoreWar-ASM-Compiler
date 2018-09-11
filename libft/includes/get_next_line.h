/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:47:55 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/07 16:38:11 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 128

typedef struct		s_head
{
	int				fd;
	char			*tmp;
	struct s_head	*next;
}					t_head;
int					get_next_line(int fd, char **line);
#endif
