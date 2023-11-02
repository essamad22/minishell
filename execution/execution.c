#include "minishell.h"

char *ft_readline()
{
    char    *line;
    
    line = readline(C_GREEN"MINISHELL $> "C_RESET);
    return (line);
}

void execution(int argc, char *argv[], t_data **envp, t_info *info)
{
    if (argc == 1)
    {
        if (strcmp(argv[0], "exit") == 0)
            ft_exit(NULL); // Remplacer NULL par la structure appropriée si nécessaire
        else if (strcmp(argv[0], "cd") == 0)
            ft_cd(NULL, envp); // Remplacer NULL par la structure appropriée si nécessaire
        else if (strcmp(argv[0], "pwd") == 0)
            printf("%s\n", getpwd());
        else if (strcmp(argv[0], "export") == 0)
            ft_export(NULL, envp, info); // Remplacer NULL par la structure appropriée si nécessaire
        else if (strcmp(argv[0], "unset") == 0)
            ft_unset(NULL, envp); // Remplacer NULL par la structure appropriée si nécessaire
        else
            one_cmd(argc, argv, xenvp);
    }
    else
    {
        printf("Error multiple pipes");
    }
}



// int main(int ac, char **av, char **env)
// {
//     char        *line;

//     line = NULL;
//     while (1)
//     {
//         line = ft_readline();
//         if (line == NULL)
//             break;
//         add_history(line);
//         execution(int argc, char *argv[], t_data **envp, t_info *info);
//     }
//     (void)av;
//     (void)ac;
//     (void)env;
//     return (0);
// }