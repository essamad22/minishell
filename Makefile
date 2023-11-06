# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 21:21:50 by aakhtab           #+#    #+#              #
#    Updated: 2023/11/06 07:42:57 by aakhtab          ###   ########.fr        #
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

SRCS			=	src/main.c src/lexer/lexer.c src/lexer/tokens.c 	\
					src/parser/command_tab.c src/lexer/item_utils.c		\
					src/lexer/quots.c src/utils.c src/utils_2.c src/parser/expantion.c 	\
					src/parser/parsing_utils.c src/parser/quots_utils.c		\
					src/parser/re_token.c src/parser/redir.c

OBJS			=	$(SRCS:.c=.o)

CFLAGS			=	-Wall -Wextra -Werror -g3 #-fsanitize=address

NAME			=	minishell

LIBFT		= lib/libft.a


all:	${NAME}


${NAME}:	$(LIBFT) ${OBJS} 
			@$(CC) $(CFLAGS) $(SRCS) lib/libft.a -o $(NAME) -lreadline


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
