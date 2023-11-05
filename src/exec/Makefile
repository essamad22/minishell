NAME = minishell


SRCS =	utils.c\
		minishell.c \
		exec.c\
		exec_part2.c\
		exec_utls.c\
		builtins.c\
		builtins_utls.c\
		export.c\
		unset.c\
		heredoc.c\
		echo_utls.c\
		utils_2.c\
		ft_strjoin.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/utils.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/utils_2.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/parser/command_tab.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/parser/expantion.c \
		/Users/nasrollahkhachabi/Desktop/minishell2/src/parser/parsing_utils.c \
		/Users/nasrollahkhachabi/Desktop/minishell2/src/parser/quots_utils.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/parser/re_token.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/parser/redir.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/lexer/item_utils.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/lexer/lexer.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/lexer/quots.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/src/lexer/tokens.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_atoi.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_atol.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_bzero.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_calloc.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_isalnum.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_isalpha.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_isascii.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_isdigit.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_isprint.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_itoa.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstadd_back.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstadd_front.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstclear.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstdelone.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstiter.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstlast.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstnew.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_lstsize.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_memchr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_memcmp.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_memcpy.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_memmove.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_memset.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_printf.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putadd.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putchar_fd.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putchar.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putendl_fd.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_puthex.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putnbr_fd.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putnbr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putstr_fd.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putstr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_putunbr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_split.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strchr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strcmp.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strdup.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_striteri.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strjoin.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strlcat.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strlcpy.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strlen.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strmapi.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strncmp.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strnstr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strrchr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_strtrim.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_substr.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_tolower.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/ft_toupper.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/get_next_line_utils.c\
		/Users/nasrollahkhachabi/Desktop/minishell2/lib/get_next_line.c\


OBJS = ${SRCS:.c=.o}

CNTRL = @stty -echoctl

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

${NAME} : ${SRCS}
	${CNTRL}
	${CC}  ${CFLAGS} ${SRCS} -lreadline -o ${NAME} 
	@tput setaf 2; echo "MINISHELL IS READY"

all : ${NAME}

clean :
	${RM} ${OBJS}

	@tput setaf 1; echo "OBJECTS REMOVED"

fclean : clean
	${RM} ${NAME}
	@tput setaf 1; echo "MINISHELL REMOVED"

re : fclean all

.phony: all clean fclean re
