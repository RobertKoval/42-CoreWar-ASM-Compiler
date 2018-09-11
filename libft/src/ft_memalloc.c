/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:09:28 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/20 12:00:16 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*arr;

	arr = NULL;
	arr = malloc(size);
	if (arr != NULL)
	{
		ft_bzero(arr, size);
		return (arr);
	}
	else
		return (NULL);
}
