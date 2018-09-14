/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 13:22:21 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/10 21:57:58 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "op.h"
# include "tokens.h"
# include <fcntl.h>
/*
** List of error types
*/
typedef enum 	e_error_types
{
	ET_UNDEFINED,
	ET_UNDEFINED_ERROR,
	ET_UNDEFINED_STRING,
	ET_BAD_ARGUMENT,
	ET_CANT_OPEN_FILE,
	ET_CANT_CREATE_FILE,
	ET_NO_QUOTES,
	ET_NAME_AGAIN,
	ET_NAME_NO_STRING,
	ET_NAME_TO_SHORT,
	ET_NAME_TO_LONG,
	ET_DESC_AGAIN,
	ET_DESC_NO_STRING,
	ET_DESC_TO_SHORT,
	ET_DESC_TO_LONG,
	ET_LABEL_TO_SHORT,
	ET_LABEL_MANY_CHARS,
	ET_LABEL_DUPLICATE,
	ET_NO_COMMENT_CMD,
	ET_NO_NAME_CMD
}				t_error_types;
/*
** Print error to stdout
*/
void	ft_error(t_error_types err, t_token *tok);

typedef struct		s_app_state
{
	_Bool			app_name;
	_Bool			app_desc;
}					t_app_state;

/*
** Application structure
*/
typedef struct	s_application
{
	char 		*name;
	char 		*line;
	size_t		row;
	int 		fd_input;
	int 		fd_output;
	t_app_state		state;
	t_token		*last_token;
	t_token		*tokens;
}				t_application;

/*
 * Main functions
 */
void	ft_tokenizer(t_application *app);
t_token	*ft_save_token(t_application *app, const char *str , size_t col);
void	ft_check_operation(t_token *a);
void	ft_check_source_structure(t_application *app);
void	ft_check_label_code(t_application *app);
void	ft_write_app(t_application *app);
/*
 * Validation
 */
int 	ft_valid_label(const char *str);
int 	ft_valid_opcode(const char *str);
int 	ft_valid_argument(char *str);
int 	ft_valid_registr(const char *str);
int 	ft_valid_direct_int(const char *str);
int 	ft_valid_indirect_int(const char *str);
int 	ft_valid_direct_label(const char *str);
int 	ft_valid_indirect_label(const char *str);
void		ft_check_symbols(t_token *a);

/*
 * Utillity
 */
size_t 	ft_skip_spaces(const char *str);
int		ft_to_big_endian(int n);
short 	ft_to_big_sendian(short n);
#endif
