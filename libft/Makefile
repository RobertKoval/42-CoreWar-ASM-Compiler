# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 12:48:24 by rkoval            #+#    #+#              #
#    Updated: 2018/07/10 15:35:10 by rkoval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_itoa.c ft_lstmap.c ft_memcmp.c ft_putchar.c \
		ft_putnbr_fd.c ft_strappend.c ft_strcpy.c ft_striteri.c  ft_strmapi.c \
		ft_strnew.c ft_strsplit.c ft_toupper.c ft_bitarray.c ft_isascii.c \
		ft_lstadd.c ft_lstnew.c ft_memcpy.c ft_putchar_fd.c ft_putstr.c \
		ft_strcat.c ft_strdel.c ft_strjoin.c ft_strncat.c ft_strnstr.c \
		ft_strstr.c ft_wcharlen.c ft_bzero.c ft_isdigit.c ft_lstdel.c \
		ft_memalloc.c ft_memdel.c ft_putendl.c ft_putstr_fd.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strncmp.c ft_strprepend.c ft_strsub.c \
		ft_wcslen.c ft_digilen.c ft_isprint.c ft_lstdelone.c ft_memccpy.c \
		ft_memmove.c ft_putendl_fd.c ft_putwchar.c  ft_strclr.c ft_strequ.c \
		ft_strlen.c ft_strncpy.c ft_strrchr.c ft_strtrim.c ft_wordcount.c \
		ft_isalnum.c ft_isspace.c ft_lstiter.c ft_memchr.c ft_memset.c \
		ft_putnbr.c ft_putwcstr.c ft_strcmp.c ft_striter.c ft_strmap.c \
		ft_strnequ.c ft_strrev.c ft_tolower.c get_next_line.c ft_printf.c \
		ft_printf/chars.c ft_printf/convert_to.c ft_printf/ints.c \
		ft_printf/itoutf.c ft_printf/mods.c ft_printf/read_tmplt.c \
		ft_printf/speciefer.c ft_printf/strings.c ft_printf/utils.c  \
		ft_printf/utils2.c get_next_int.c get_next_word.c ft_strlcpy.c


OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
INC = libft.h get_next_line.h ft_printf.h

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

#SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
#OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
#INCS = $(addprefix $(INC_DIR)/, $(INC))

CFLAGS = -Wall -Werror -Wextra -std=c11
CPPFLAGS = -Iincludes


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
	ar -rcs $(NAME) $(OBJ)
	@echo "$(GREEN)libft.a $(BOLDRED)made$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/ft_printf
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Objects $(MAGENTA)removed!$(RESET)!"

fclean: clean
	rm -rf $(NAME)
	@echo "$(GREEN)libft.a $(MAGENTA)removed!$(RESET)!"

re: fclean all
