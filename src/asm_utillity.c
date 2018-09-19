/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_utillity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:59:36 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/19 15:18:15 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**				Convert Little-endian to big endian
**
**	Example -> int: 305223233 -> hex: 0x12315641 -> 12 31 56 41  (4 byte)
**	!BUT! Our system store this value as: 0x41563112
**	We must reverse bytes, because we want big-endian. So we need 0x41563112
**  and our system will store this value as 0x12315641.
**
**    [0001 0010] [0011 0001] [0101 0110] [0100 0001] = 305223233 = 12 31 56 41
**
**  1) Left Shift value by 8 (8 bit = 1 byte):
**    [0001 0010] [0011 0001] [0101 0110] [0100 0001] << 8 =
**  = [0011 0001] [0101 0110] [0100 0001] [0000 0000] = 827736320 = 31 56 41 00
**
**	2) make AND operation with result and 0xFF00FF00:
**    [0011 0001] [0101 0110] [0100 0001] [0000 0000] - 0x31564100
**  & [1111 1111] [0000 0000] [1111 1111] [0000 0000] - 0xFF00FF00 &
**    -----------------------------------------------
**    [0011 0001] [0000 0000] [0100 0001] [0000 0000] = 0x31004100
**
** 3) Right Shift value by 8:
**    [0001 0010] [0011 0001] [0101 0110] [0100 0001] >> 8 =
**  = [0000 0000] [0001 0010] [0011 0001] [0101 0110] 0x[00]123156
**
** 4) make AND operation with result and 0x[00]FF00FF:
**    [0000 0000] [0001 0010] [0011 0001] [0101 0110] - 0x[00]123156
**  & [0000 0000] [1111 1111] [0000 0000] [1111 1111] - 0x[00]FF00FF
**    -----------------------------------------------
**    [0000 0000] [0001 0010] [0000 0000] [0101 0110] = 0x[00]120056
**
** 5) make OR operation with 2 new previous values 0x31004100 and 0x00120056:
**    [0011 0001] [0000 0000] [0100 0001] [0000 0000] - 0x31004100
**  | [0000 0000] [0001 0010] [0000 0000] [0101 0110] - 0x00120056
**    -----------------------------------------------
**    [0011 0001] [0001 0010] [0100 0001] [0101 0110] = 0x31124156 -> int nv;
**
** 6) Left Shift nv by 16:
** 	  0x31124156 << 16 = 0x41560000
**
** 7) Right Shift nb by 16:
**    0x31124156 >> 16 = 0x00003112
**
** 7.1) make AND operation  /// Work with negative numbers
** 	  [0011 0001] [0001 0011] - 0x[0000]3112
** 	& [1111 1111] [1111 1111] - 0x[0000]FFFF
** 	  -----------------------
** 	  [0011 0001] [0001 0011] - 0x3112
**
** 8) 0x41560000 | 0x00003112 = 0x41563112
*/

/*
** 					Example with negative number
**  -68954 = 0xFFFEF2A6
**  0xFFFEF2A6 << 8 = 0xFEF2A600 & 0xFF00FF00 -> 0xFE00A600
**  0xFFFEF2A6 >> 8 = 0xFFFFFEF2 & 0x00FF00FF -> 0x00FF00F2  |
**  										     0xFEFFA6F2
**
**  0xFEFFA6F2 << 16 = 							 0xA6F20000
**  0xFEFFA6F2 >> 16 = 0xFFFFFEFF & 0x0000FFFF = 0x0000FEFF  |
**  											 0xA6F2FEFF
*/

int		ft_to_big_endian(int n)
{
	int nv;

	nv = (((n << 8) & 0xFF00FF00) | ((n >> 8) & 0xFF00FF));
	return ((nv << 16) | ((nv >> 16) & 0xFFFF));
}

short	ft_to_big_sendian(short n)
{
	return ((n << 8) | ((n >> 8) & 0xFF));
}

size_t	ft_skip_spaces(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		return (i);
	return (0);
}

/*
** Get operation index
*/

int		ft_get_opcode(const char *str)
{
	int i;

	i = 0;
	while (g_op_tab[i].instruct)
	{
		if (ft_strcmp(g_op_tab[i].instruct, str) == 0)
			return (i);
		i++;
	}
	return (-1);
}
