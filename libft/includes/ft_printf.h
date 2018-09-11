/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:09:58 by rkoval            #+#    #+#             */
/*   Updated: 2018/06/17 16:53:36 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FT_PRINTF_BUFF_SIZE 128
# include <stdarg.h>
# include "libft.h"

/*
** 				SHORTCUT FOT BITARRAY
*/
# define GET_BIT(n)	ft_get_bit(&data->flags, n)
# define SET_BIT(n)	ft_set_bit(&data->flags, n)
# define RM_BIT(n)	ft_clear_bit(&data->flags, n)

/*
** 				Colors
*/
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"

/*
** 				STRUCT DESCRIPTION
** buffer[FT_PRINTF_BUFF_SIZE + 1] -> >= 0 buffer
** *arg -> list with arguments
** *fmt -> argument string from ft_printf
** *wstr -> for wchar string tmp
** *tmplt -> save template from *fmt for next convertation
** *var -> contain ints in str
** xou -> store uint argument
** did -> stori int argument
** flags -> bitarray with all information
** print_len -> number of printed chars
** tmplt_len -> length of template string
** fd -> file descriptor, default = 1; {err} = 2 = stderror, {file} = fd
** wc -> strore wide char
** minus -> true if int var < 0
** buff_marker -> iterator for buffer
**  c -> just for 1 char;
*/
typedef uint32_t	t_bitarray;
typedef struct	s_printf
{
	char		buffer[FT_PRINTF_BUFF_SIZE + 1];
	va_list		*arg;
	char		*fmt;
	wchar_t		*wstr;
	char		*tmplt;
	char		*var;
	uintmax_t	xou;
	intmax_t	did;
	t_bitarray	flags;
	int			print_len;
	int			tmplt_len;
	int			var_len;
	int			width;
	int			precision;
	int			fd;
	wchar_t		wc;
	short		minus;
	short		buff_marker;
	char		c;
}				t_printf;

# define CMPR(i,x)	((data->tmplt[i] == (x)) ? 1 : 0)

/*
**				BIT ARRAY DESCRIPTION
**  ^ = empty, from 0 to 31;
**0 1  2  3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
**^,#,' ',0,+,-,^,^,^,z,j, ll,l, h, hh,^, s, p, i, o, u, x, X, c, b, ^, ^, ^, %
**
** d == i , D|O|U|C|S = l + d|o|u|c|s
*/

int				ft_printf(const char *format, ...);
void			ft_read_fmt(t_printf *data);
void			ft_converter(t_printf *data);
void			ft_process(t_printf *data);

/*
**				MODS
**  %{err}  - write to stderror
**  %{file} - write to file -> first argument file descriptor
**  %{red/grn/blu/etc.} - start color
**  %{eoc} - end of color
*/
void			ft_mods(t_printf *data);

/*
** 				UTILITY'S
*/
void			ft_add_hash(t_printf *data);
void			ft_padding_xou(t_printf *data, int a, char c);
void			ft_put_width(t_printf *data);
void			ft_repair_flags(t_printf *data);
void			ft_clear_data(t_printf *data);
void			ft_flush_buffer(t_printf *data);
void			ft_add_char_to_buff(t_printf *data, char c);
void			ft_add_str_to_buff(t_printf *data, char *str);
void			ft_send_to_handler(t_printf *data);
void			ft_wcs_to_buff(t_printf *data, int c);
/*
**				TEMPLATE RECOGNIZE
*/
void			ft_save_bitspecifier(t_printf *data);
void			ft_save_bitflags(t_printf *data);
void			ft_len(t_printf *data);
void			ft_save_bitlength(t_printf *data);

/*
**				CONVERT ARG TO STR
*/
char			*ft_uitobin(unsigned int num);
char			*ft_llitobin(long long int num);
char			*ft_itohex(unsigned int num);
char			*ft_uitohex(uintmax_t num);
char			*ft_uitooct(uintmax_t num);
char			*ft_itoutf(int num);
/*
**				WORKERS
*/
void			ft_process_char(t_printf *data);
void			ft_process_wchar(t_printf *data);
void			ft_process_str(t_printf *data);
void			ft_process_wstr(t_printf *data);
void			ft_process_int(t_printf *data);
void			ft_process_xou(t_printf *data);
void			ft_xou(t_printf *data);
void			ft_integers(t_printf *data);
void			ft_chars(t_printf *data);
void			ft_strings(t_printf *data);
#endif
