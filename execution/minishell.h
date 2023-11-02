#ifndef MINISHELL_H
# define MINISHELL_H

#include "/Users/nasrollahkhachabi/Desktop/mini_shell/execution/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>


# define EIAD ": is a directory\n"
# define ENSFD ": No such file or directory\n"
# define ECNF ": command not found\n"
# define EPD ": Permission denied\n"
# define ESYNTX "minishell: syntax error near unexpected token `"
# define EAMBGRD ": ambiguous redirect\n"

//Parsing
# define C_GREEN   "\033[0;1;3;32m"
# define C_RESET   "\033[0;37m"
//Parsing

typedef struct t_data
{
	char			*content;
	struct t_data	*next;

}					t_data;

typedef struct s_list
{
	char			**file_name;
	char			**commandes;
	char			**type;
	struct s_list	*next;
}	t_list;


typedef struct t_info
{

	int				i_exp;
	int				check;
	int				check1;
	
}					t_info;


typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}			t_env;

typedef struct s_global
{
	t_env		*env;
	t_env		*export;
}			t_global;

int	strlenhtal(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strlen1(const char *s);
char	*ft_strjoin10(char *s1, char *s2);
char	*getz(void);
char	*getpwd(void);
void	printerr(char *s1, char *s2, char *s3);
char	*ft_strjoin1(char *s1, char *s2);
int	checktossawiplace(char *s);
char	*bringbeforetossawi(char *s);
char	*bringaftertossawi(char *s);
void	ft_exit(t_list *cmd);
int	ft_cd(t_list *p, t_data **data);
void	ft_export(t_list *p, t_data **data, t_info *info);
int	ft_unset(t_list *p, t_data **data);
void one_cmd(int argc, char *argv[], char **envp);
int	ft_strncmp(const char *s1, const char *s2, size_t n);



#endif