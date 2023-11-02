src = cd.c export.c exit.c pipes.c pwd.c redirection.c unset.c exec_utils.c \
		#execution.c

O_files = $(src:.c=.o)
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address 

NAME = minishell

$(NAME) : $(O_files)
	gcc -lreadline $(CFLAGS) $(O_files)   -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean : 
	rm -rf $(O_files) $(bonus_O)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
