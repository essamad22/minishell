/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:01:28 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/06 07:28:56 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data  g_data;

char *ft_readline()
{
    char    *line;
    
    line = readline(C_GREEN"MINISHELL $> "C_RESET);
    return (line);
}

void    set_data(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    g_data.env_dup = ft_envdup(env);
    g_data.env_lst = ft_envlst(env);
    g_data.exit_status = 0;
}

int main(int ac, char **av, char **env)
{
    char        *line;
    t_cmd_tab   *cmd_tab;

    line = NULL;
    set_data(ac , av, env);
    while (1)
    {
        cmd_tab = NULL;
        line = ft_readline();
        if (line == NULL)
            break;
        add_history(line);
        if (ft_strncmp(line, "exit", 5) == 0)
        {
            free(line);
            // clear_data(&cmd_tab);
            free(cmd_tab);
            exit(0);
        }
        cmd_tab = command_tab(line);
        if (cmd_tab == NULL)
            break;
        free(line);
        // clear_data(&cmd_tab);
        free(cmd_tab);
    }
    return (0);
}