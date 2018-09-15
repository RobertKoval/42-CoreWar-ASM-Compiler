/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 13:50:19 by rkoval            #+#    #+#             */
/*   Updated: 2018/09/15 14:14:34 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/asm.h"

void	ft_error3(t_error_types err, t_token *tok)
{
	if (err == ET_UNDEFINED)
		ft_printf("MAGIK ERROR! YOU ARE WITCH!\n");
	if (err == ET_UNDEFINED_ERROR)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Undefined instruction\n"
				"%s\n%*c\n", tok->cur_pos[0], tok->cur_pos[1] + 1, tok->in_file,
				  tok->cur_pos[1] + 1, '^');
	else if (err == ET_UNDEFINED_STRING)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Undefined string\n%s\n",
				  tok->next->cur_pos[0], 0, tok->next->in_file);
	else if (err == ET_NO_COMMENT_CMD)
		ft_printf("%{err}No %s command after name!"
			" [002:000]\n", COMMENT_CMD_STRING);
	else if (err == ET_NO_NAME_CMD)
		ft_printf("%{err}No %s command! [001:000]\n", NAME_CMD_STRING);
}

void	ft_error2(t_error_types err, t_token *tok)
{
	if (err == ET_DESC_AGAIN)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] It can't be more than "
			"one \"%s\" command\n", tok->cur_pos[0], tok->cur_pos[1],
				  COMMENT_CMD_STRING);
	else if (err == ET_DESC_NO_STRING)
		ft_printf("%{err}Syntax error at [%03zu:%03zu] "
			"No description string\n%s\n%*c\n", tok->cur_pos[0],
				  tok->cur_str_len, tok->in_file, tok->cur_str_len + 2, '^');
	else if (err == ET_DESC_TO_LONG)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Description to long\n"
			"%s\n", tok->cur_pos[0], tok->cur_str_len, tok->in_file);
	if (err == ET_LABEL_TO_SHORT)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Label to short\n"
			"%s\n%*c\n", tok->cur_pos[0], tok->cur_str_len, tok->in_file, '^');
	else if (err == ET_LABEL_MANY_CHARS)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] A lot of LABEL_CHAR\n"
			"%s\n%*c\n", tok->cur_pos[0], tok->cur_str_len, tok->in_file, '^');
	else if (err == ET_LABEL_DUPLICATE)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Label exist\n"
			"%s\n%*c\n", tok->cur_pos[0], tok->cur_str_len, tok->in_file, '^');
	else
		ft_error3(err, tok);
}

void	ft_error(t_error_types err, t_token *tok)
{
	if (err == ET_BAD_ARGUMENT)
		ft_printf("%{err}Bad arguments!\nusage: ./asm <filename.s>\n");
	else if (err == ET_CANT_OPEN_FILE)
		ft_printf("%{err}Can't open source file\n");
	else if (err == ET_CANT_CREATE_FILE)
		ft_printf("%{err}Can't create output file\n");
	else if (err == ET_NO_QUOTES)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] "
			"No quotes!\n%s\n%*c\n", tok->cur_pos[0], ft_strlen(tok->in_file)+1,
				  tok->in_file, ft_strlen(tok->in_file) + 1, '^');
	else if (err == ET_NAME_AGAIN)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] It can't be more than "
					"one \"%s\" command\n", tok->cur_pos[0], tok->cur_pos[1],
				  NAME_CMD_STRING);
	else if (err == ET_NAME_NO_STRING)
		ft_printf("%{err}Syntax error at [%03zu:%03zu] "
			"No name string\n%s\n",
				  tok->cur_pos[0], tok->cur_str_len, tok->in_file, '^');
	else if (err == ET_NAME_TO_SHORT)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] Name to short\n%s\n",
				  tok->cur_pos[0], tok->cur_str_len, tok->in_file);
	else if (err == ET_NAME_TO_LONG)
		ft_printf("%{err}Lexical error at [%03zu:%03zu] "
						  "Name to long\n%s\n",
				  tok->cur_pos[0], tok->cur_str_len, tok->in_file);
	else
		ft_error2(err, tok);
	exit(1);
}