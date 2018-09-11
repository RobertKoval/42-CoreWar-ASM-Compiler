/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 18:43:44 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/10 13:30:00 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKENS_H
# define TOKENS_H

# include "asm.h"

typedef union		U_ONE_B
{
	char			ob;
	struct
	{
		char		b8:2;
		char		b6:2;
		char		b4:2;
		char		b2:2;
	};
}					t_byte;

typedef enum		e_token_type
{
	TT_UNDEFINED,
	TT_NAME,
	TT_COMMENT,
	TT_STRING,
	TT_LABEL,
	TT_OPCODE,
	TT_ARGUMENT,
	TT_SEPARATE_CHAR
}					t_token_type;

typedef enum		e_argtype
{
	AT_UNDEFINED,
	AT_DIRECT_INT,
	AT_DIRECT_LABEL,
	AT_INDIRECT_INT,
	AT_INDIRECT_LABEL,
	AT_REGISTR
}					t_argtype;

typedef enum		e_arg_size
{
	AS_ZERO = 0,
	AS_ONE = 1,
	AS_TWO = 2,
	AS_FOUR = 4
}					t_arg_size;

typedef struct		s_token
{

	int 			id;
	char 			*in_file;
	char 			*cur_str;

	size_t			cur_str_len;
	size_t			cur_pos[2];  //row | first char


	t_token_type	type_of_token;
	t_argtype		arg_type;
	t_arg_size		arg_size;

	unsigned char 	ophex;
	unsigned char	codage;
	int				four_b_val;
	short			two_b_val;
	char			one_b_val;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;



#endif
