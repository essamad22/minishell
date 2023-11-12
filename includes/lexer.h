/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:52 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/12 16:44:47 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include <stdbool.h>

typedef enum e_tokens
{
	WORD = -1,
	PIPE = '|',
	SEMICOLON = ';',
	GREAT = '>',
	LESS = '<',
	NEW_LINE = '\n',
    TILDE = '~',
	QUOTE = '\'',
	DQUOTE = '\"',
	ENV = '$',
	SPAC = ' ',
	BACK_SLASH = '\\',
	APPEND,
	HEREDOC,
	END
}					t_tokens;

typedef enum e_states
{
	GENERAL,
	IN_QUOTE,
	IN_DQUOTE
}					t_states;

typedef struct s_item
{
	char			*content;
	int				len;
	bool			is_ambiguous;
	t_tokens		type;
	t_tokens		redir_type;
	t_states		state;
	struct s_item	*next;
	struct s_item	*prev;
	struct s_item	*head;
	struct s_item	*tail;
}					t_item;

t_item				*lexer(char *line);
int					get_token(t_item **list, char *cmd_line, int *stat);
int					word(t_item **list, char *cmd_line, int *stat);
int					tokens(t_item **list, char type, int *stat);
t_item				*new_item(char *value, int len, int type, int stat);
void				add_item(t_item **list, t_item *item);
void				rm_item(t_item **items);
int					in_quote(t_item **list, char type, int *stat);
int					s_quote(t_item **list, int *stat, int type);
int					d_quote(t_item **list, int *stat, int type);
int					env(t_item **list, char *cmd, int *stat);
void				print_tokens(t_item *tokens);
int					ft_isenv(int c);

#endif