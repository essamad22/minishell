# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 21:21:50 by aakhtab           #+#    #+#              #
#    Updated: 2023/11/12 16:09:38 by aakhtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====COLORS=====#
RESET	= \033[0m
GRAY		= \033[0;90m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
PURPLE		= \033[0;35m
#================#

CC			=	cc

SRCS			=	src/lexer/lexer.c src/lexer/tokens.c 	\
					src/parser/command_tab.c src/lexer/item_utils.c		\
					src/lexer/quots.c src/utils.c src/utils_2.c src/parser/expantion.c 	\
					src/parser/parsing_utils.c src/parser/quots_utils.c		\
					src/parser/re_token.c src/parser/redir.c 	\
					src/parser/cmd_utils.c	\
					src/exec/utils.c\
					src/minishell.c \
					src/exec/exec.c\
					src/exec/exec_part2.c\
					src/exec/exec_utls.c\
					src/exec/builtins.c\
					src/exec/builtins_utls.c\
					src/exec/export.c\
					src/exec/unset.c\
					src/exec/heredoc.c\
					src/exec/echo_utls.c\
					src/exec/utils_2.c\
					src/exec/ft_strjoin.c\
					src/heredoc_utils.c\
					src/syntax_err.c\
					src/utils_3.c\

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address

NAME			=	minishell

LIBFT		= lib/libft.a


all:	${NAME}


${NAME}:	$(LIBFT) ${OBJS} 
			@$(CC) $(CFLAGS) $(SRCS) lib/libft.a -lreadline -o $(NAME) 


$(LIBFT)	:
	@make -C lib

##---- need to modier----------
%.o	: %.c
	@${CC} ${CFLAGS} -c $< -o $@
##-----------------------------

clean:	
			@make clean -C lib
			@rm -f $(OBJS)
			@printf "$(YELLOW)\r    [OBJECTS CLEANED 🗑️$(RESET)"

fclean:	clean
			@make fclean -C lib
			@rm -f ${NAME}
			@printf "\r												"
			@printf "$(RED)\r     [EVERYTHING CLEANED 👌]    \n$(RESET)"
			
re:	fclean all
