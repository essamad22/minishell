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
		../utils.c\
		../utils_2.c\
		../parser/command_tab.c\
		../parser/expantion.c \
		../parser/parsing_utils.c \
		../parser/quots_utils.c\
		../parser/re_token.c\
		../parser/redir.c\
		../lexer/item_utils.c\
		../lexer/lexer.c\
		../lexer/quots.c\
		../lexer/tokens.c\
		../../lib/ft_atoi.c\
		../../lib/ft_atol.c\
		../../lib/ft_bzero.c\
		../../lib/ft_calloc.c\
		../../lib/ft_isalnum.c\
		../../lib/ft_isalpha.c\
		../../lib/ft_isascii.c\
		../../lib/ft_isdigit.c\
		../../lib/ft_isprint.c\
		../../lib/ft_itoa.c\
		../../lib/ft_lstadd_back.c\
		../../lib/ft_lstadd_front.c\
		../../lib/ft_lstclear.c\
		../../lib/ft_lstdelone.c\
		../../lib/ft_lstiter.c\
		../../lib/ft_lstlast.c\
		../../lib/ft_lstnew.c\
		../../lib/ft_lstsize.c\
		../../lib/ft_memchr.c\
		../../lib/ft_memcmp.c\
		../../lib/ft_memcpy.c\
		../../lib/ft_memmove.c\
		../../lib/ft_memset.c\
		../../lib/ft_printf.c\
		../../lib/ft_putadd.c\
		../../lib/ft_putchar_fd.c\
		../../lib/ft_putchar.c\
		../../lib/ft_putendl_fd.c\
		../../lib/ft_puthex.c\
		../../lib/ft_putnbr_fd.c\
		../../lib/ft_putnbr.c\
		../../lib/ft_putstr_fd.c\
		../../lib/ft_putstr.c\
		../../lib/ft_putunbr.c\
		../../lib/ft_split.c\
		../../lib/ft_strchr.c\
		../../lib/ft_strcmp.c\
		../../lib/ft_strdup.c\
		../../lib/ft_striteri.c\
		../../lib/ft_strjoin.c\
		../../lib/ft_strlcat.c\
		../../lib/ft_strlcpy.c\
		../../lib/ft_strlen.c\
		../../lib/ft_strmapi.c\
		../../lib/ft_strncmp.c\
		../../lib/ft_strnstr.c\
		../../lib/ft_strrchr.c\
		../../lib/ft_strtrim.c\
		../../lib/ft_substr.c\
		../../lib/ft_tolower.c\
		../../lib/ft_toupper.c\
		../../lib/get_next_line_utils.c\
		../../lib/get_next_line.c\


OBJS = ${SRCS:.c=.o}

CNTRL = @stty -echoctl

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address


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
