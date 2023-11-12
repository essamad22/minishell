/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:01:17 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 12:15:59 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft.h"
# include "lexer.h"
# include "parser.h"
# include "execution.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define C_GREEN   "\033[0;1;3;32m"
# define C_RESET   "\033[0;37m"
# define MAX_LEN 1024



//






typedef struct s_data
{
    char        **env_dup;
    t_env_list  *env_lst;
	t_vr 		*export;
    int         exit_status;
    int         heredoc;
    int         syntax_error;
    int         empty_quote;
    char			*content; // added by Nasro
	int	exitheredoc;
	int	quit_flag;
	int	here_doc_flag;
	int	rd_error;
	int	cd;
	int fd;
	int flag;
	int	h_sig;
	struct t_data	*next;    // added by Nasro 
}   t_data;


extern t_data g_data;



#endif