# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 18:41:29 by dpattij           #+#    #+#              #
#    Updated: 2020/02/20 20:22:08 by dpattij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################

NAME			=	minishell

FLAGS			=	-Wall -Wextra -Werror -pedantic -std=c89
FLAGS_DEBUG		=	-Wall -Wextra -g
FLAGS_RDBG		=	-Wall -Wextra -Werror -pedantic -std=c89 -g
FLAGS_BIN		=
FLAGS_BIN_ASAN	=	-fsanitize=address

INCLUDE_DIRS	=	./include/ ./libft/ ./libftprintf/include/
SRC_DIR			=	./src/
OBJ_DIR			=	./obj/
SRC_SUBDIRS		=	runtime_loop std

LIBFT_DIR		=	./libft/
LIBFTPRINTF_DIR =	./libftprintf/

SRC_FILES		=	main \
					runtime_loop/display_prompt \
					runtime_loop/read_char \
					runtime_loop/read_line \
					runtime_loop/take_input \
					runtime_loop/runtime_loop \
					std/ft_realloc

###########################

INCLUDE_DIRS := $(INCLUDE_DIRS:%=-I%)
SRC_FILES := $(SRC_FILES:%=%.o)
OBJ_FILES := $(SRC_FILES:%=$(OBJ_DIR)%)
OBJ_SUBDIRS := $(SRC_SUBDIRS:%=$(OBJ_DIR)%)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) libft
	@$(MAKE) libftprintf
	@echo BUILD $(NAME)
	@$(CC)	$^ \
			-o $(NAME) \
			-L $(LIBFT_DIR) -lft \
			-L $(LIBFTPRINTF_DIR) -lftprintf \
			$(FLAGS) \
			$(FLAGS_BIN)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p	$(OBJ_DIR) \
				$(OBJ_SUBDIRS)
	@$(CC)	$(INCLUDE_DIRS) \
			-c $^ \
			-o $@ \
			$(FLAGS)
	@echo CC $^

re: fclean
	@$(MAKE)

clean:
	@$(MAKE) libftclean
	@$(MAKE) libftprintfclean
	@$(RM) -rf $(OBJ_DIR)
	@echo CLEAN $(OBJ_DIR)

fclean: clean
	@$(MAKE) libftfclean
	@$(MAKE) libftprintffclean
	@$(RM) -f $(NAME)
	@echo FCLEAN $(NAME)

debug: FLAGS = $(FLAGS_DEBUG)
debug: all
asan: FLAGS_BIN = $(FLAGS_BIN_ASAN)
asan: rdb

rdebug: fclean
	@$(MAKE) debug

rdb: FLAGS = $(FLAGS_RDBG)
rdb: re

rasan: fclean
	@$(MAKE) asan

libft:
	@$(MAKE) -C $(LIBFT_DIR)
	@echo BUILD libft

libftclean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo CLEAN libft

libftre:
	@$(MAKE) re -C $(LIBFT_DIR)
	@echo RE libft

libftfclean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo FCLEAN libft

libftprintf:
	@$(MAKE) bonus -C $(LIBFTPRINTF_DIR)
	@echo BUILD libftprintf

libftprintfclean:
	@$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@echo CLEAN libftprintf

libftprintfre:
	@$(MAKE) re -C $(LIBFTPRINTF_DIR)
	@echo RE libftprintf

libftprintffclean:
	@$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@echo FCLEAN libftprintf

.PHONY:	all re clean fclean libft libftprintf \
		libftclean libftre libftfclean libftprintfclean \
		libftprintfre libftprintffclean
