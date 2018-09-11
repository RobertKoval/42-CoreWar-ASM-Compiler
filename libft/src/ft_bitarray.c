/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:42:11 by rkoval            #+#    #+#             */
/*   Updated: 2018/05/23 16:13:12 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_set_bit(t_bitarray *arr, int n)
{
	arr[ARR_OFFSET(n)] |= (1 << BIT_OFFSET(n));
}

void	ft_clear_bit(t_bitarray *arr, int n)
{
	arr[ARR_OFFSET(n)] &= ~(1 << BIT_OFFSET(n));
}

int		ft_get_bit(const t_bitarray *arr, int n)
{
	t_bitarray bit;

	bit = arr[ARR_OFFSET(n)] & (1 << BIT_OFFSET(n));
	return (bit != 0);
}

void	ft_clear_bitarray(t_bitarray *arr)
{
	*arr = 0;
}

void	ft_print_bitarray(t_bitarray *arr)
{
	register size_t i;

	i = 0;
	while (i < BITS_PER_ARRAY)
	{
		ft_putnbr(ft_get_bit(arr, i));
		i++;
	}
	ft_putchar('\n');
}
