# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 14:19:53 by rkoval            #+#    #+#              #
#    Updated: 2018/07/11 11:41:42 by rkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = asm_main.c asm_check_code_structure.c \
                 asm_check_operation.c \
                 asm_check_symbols.c \
                 asm_error_manager.c \
                 asm_label_fix.c \
                 asm_op.c \
                 asm_token_manager.c \
                 asm_tokenizer.c \
                 asm_utillity.c \
                 asm_validate_token.c \
                 asm_validate_token2.c \
                 asm_write_file.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INC = lem_in.h

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

LIBFT_DIR = libft/
LIBFT_INC = $(LIBFT_DIR)includes/
LIBFT = $(LIBFT_DIR)libft.a

CFLAGS = -Wall -Werror -Wextra -std=c11
CPPFLAGS = -Iincludes
LDFLAGS = -lft -L $(LIBFT_DIR)

# COLORS
RESET=		\033[0m
RED=		\033[31m
GREEN=		\033[32m
YELLOW=		\033[33m
BLUE=		\033[34m
MAGENTA=	\033[35m
CYAN=		\033[36m
WHITE=		\033[37m
BOLDRED=	\033[1m\033[31m
BOLDWHITE=	\033[1m\033[37m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(CPPFLAGS) $(LDFLAGS)
	@echo "$(GREEN)asm compiler $(BOLDRED)made$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all