/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:47:37 by rkoval            #+#    #+#             */
/*   Updated: 2018/04/17 18:40:53 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static void	ft_append(char **base, char *src)
{
	char *tmp;

	if (*base)
	{
		tmp = ft_strjoin(*base, src);
		free(*base);
		*base = tmp;
	}
	else
	{
		tmp = ft_strnew(ft_strlen(src));
		tmp = ft_strncpy(tmp, src, ft_strlen(src));
		*base = tmp;
	}
}

static void	ft_strshift(t_head *list, char **line)
{
	int		i;
	size_t	len;
	char	*to_list;

	len = ft_strlen(list->tmp);
	i = -1;
	while (list->tmp[++i])
		if (list->tmp[i] == '\n')
			break ;
	if (list->tmp[0] == '\n' && list->tmp[i + 1] != '\0')
		*line = ft_strnew(1);
	else
		*line = ft_strsub(list->tmp, 0, (unsigned int)i);
	if (len - i > 0)
	{
		to_list = ft_strsub(list->tmp, (unsigned int)i + 1, len - (i + 1));
		free(list->tmp);
		list->tmp = to_list;
	}
	else
	{
		free((list->tmp));
		list->tmp = NULL;
	}
}

static int	ft_addtoline(t_head *list, char **line)
{
	if (!list)
		return (0);
	if (list->tmp != NULL && list->tmp[0] != '\0')
		ft_strshift(list, line);
	else
		return (0);
	return (1);
}

t_head		*ft_set_head(t_head *node, int fd)
{
	t_head *p;

	p = node;
	while (p->next)
	{
		if (p->fd == fd)
			return (p);
		p = p->next;
	}
	if (p->fd == fd)
		return (p);
	else
	{
		p->next = (t_head*)malloc(sizeof(t_head));
		p = p->next;
		*p = (t_head){.fd = fd};
	}
	return (p);
}

int			get_next_line(const int fd, char **line)
{
	ssize_t			red;
	char			buf[BUFF_SIZE + 1];
	static t_head	node;
	t_head			*n_fd;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	n_fd = ft_set_head(&node, fd);
	while (!(ft_strchr(n_fd->tmp, '\n')))
	{
		red = read(fd, buf, BUFF_SIZE);
		if (red == -1)
			return (-1);
		if (red == 0)
			return (ft_addtoline(n_fd, line));
		buf[red] = '\0';
		ft_append(&n_fd->tmp, buf);
	}
	return (ft_addtoline(n_fd, line));
}
