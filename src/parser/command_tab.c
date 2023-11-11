/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:33:53 by aakhtab           #+#    #+#             */
/*   Updated: 2023/11/11 04:46:34 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_tab   *command_tab(char *cmd_line)
{
    t_item      *tokens;
    t_cmd_tab   *cmd_tab;
    int         len;

    tokens = lexer(cmd_line);
    len = cmd_len(tokens);
    cmd_tab = (t_cmd_tab *)ft_calloc(sizeof(t_cmd_tab), len + 1);
    if (!cmd_tab)
        return (NULL);
    delete_spaces(&tokens);
    tokens_iterator(tokens, cmd_tab);
    check_quote(&tokens);
    // printf("after check quots\n");
    remove_quotes(&tokens);
    fill_cmd(&tokens, &cmd_tab);
    // print_tokens(tokens);
    clear_tokens(&tokens);
    //print_cmd_tab(&cmd_tab);
    return (cmd_tab);
}

int cmd_len(t_item *tokens)
{
    int size;

    size = 1;
    if (!tokens)
        return (0);
    while (tokens)
    {
        if (tokens && tokens->type == PIPE && tokens->state == GENERAL)
            size++;
        tokens = tokens->next;
    }
    return (size);
}

void print_tokens(t_item *tokens)
{
    t_item  *tmp;

    tmp = tokens;
    printf("\033[0;1;2;31m-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\tCONTENT\t\t|\tLEN\t\t|\tTYPE\t\t|\tSTATE\t\t|\tAMBIGUOS\t|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\033[0;37m\n");
    while (tmp)
    {
        printf("\t %s\t", tmp->content);
        printf("\t|\t %d \t", tmp->len);
        if (tmp->type == WORD)
            printf("\t|\t WORD \t");
        else if (tmp->type == PIPE)
            printf("\t|\t PIPE \t");
        else if (tmp->type == SPAC)
            printf("\t|\t SPAC \t");
        else if (tmp->type == LESS)
            printf("\t|\t LESS \t");
        else if (tmp->type == GREAT)
            printf("\t|\t GREAT \t");
        else if (tmp->type == QUOTE)
            printf("\t|\t QUOTE \t");
        else if (tmp->type == DQUOTE)
            printf("\t|\t DQUOTE ");
        else if (tmp->type == ENV)
            printf("\t|\t ENV \t");
        else if (tmp->type == HEREDOC)
            printf("\t|\t HEREDOC");
        else if (tmp->type == APPEND)
            printf("\t|\t APPEND");
        if (tmp->state == GENERAL)
            printf("\t|\t GENERAL");
        else if (tmp->state == IN_QUOTE)
            printf("\t|\t IN_QUOTE");
        else if (tmp->state == IN_DQUOTE)
            printf("\t|\t IN_DQUOTE");
        if (tmp->is_ambiguous == 1)
        {
            printf("\t|\t TRUE\t\t|");
        }
        else
            printf("\t|\t FALSE\t\t|");
        printf("\n-------------------------------------------------------------------------------------------------------------------------\n");
        tmp = tmp->next;
    }
}

// void    print_cmd_tab(t_cmd_tab **cmd_tab)
// {
//     int i;
//     int j;
//     // int len;
//     t_cmd_tab *tmp;

//     i = 0;
//     // len = cmd_tab->len;
//     tmp = *cmd_tab;
//     j = -1;
//     while (tmp)
//     {
//         j = -1;
//         printf("\033[0;1;2;31m-------cmd_tab[%d]-----------\n", i);
//         printf("cmd tab %p\n", tmp);
//         while (tmp->cmd[++j])
//         {
//             printf("cmd[%d] = %s\n", j,tmp->cmd[j]);
//         }
//         while (tmp->redirs)
//         {
//             printf("in_redir = %s\t", tmp->redirs->redirect);
//             if (tmp->redirs->type == HEREDOC)
//                 printf("type = HEREDOC\n");
//             else if (tmp->redirs->type == LESS)
//                 printf("type = LESS\n");
//             else if (tmp->redirs->type == GREAT)
//                 printf("type = GREAT\n");
//             else if (tmp->redirs->type == APPEND)
//                 printf("type = APPEND\n");
//             tmp->redirs = tmp->redirs->next;
//         }
//         printf("pipe = %d\n", tmp->is_pipe);
//         i++;
//         // printf("-------cmd_tab[%d]-----------\033[0;37m\n", i++);
//         tmp = tmp->next;
//     }
//     // while (len > 0)
//     // {
//     //     j = 0;
//     //     printf("\033[0;1;2;31m-------cmd_tab[%d]-----------\n", i);
//     //     printf("cmd = \n");
//     //     while (tmp->cmd[j])
//     //     {
//     //         printf("%s\t", tmp->cmd[j]);
//     //         j++;
//     //     }
//     //     printf("cmd = %s\n", tmp->cmd[i]);
//     //     if (tmp->in_redir)
//     //     {
//     //         while (tmp->in_redir)
//     //         {
//     //             printf("in_redir = %s\n", tmp->in_redir->redirect);
//     //             tmp->in_redir = tmp->in_redir->next;
//     //         }
//     //     }
//     //     else if (tmp->out_redir)
//     //     {
//     //         while (tmp->out_redir)
//     //         {
//     //             printf("out_redir = %s\n", tmp->out_redir->redirect);
//     //             tmp->out_redir = tmp->out_redir->next;
//     //         }
//     //     }
//     //     if (tmp->is_pipe == 1)
//     //         printf("pipe = %d\n", tmp->is_pipe);
//     //     printf("-------cmd_tab[%d]-----------\033[0;37m\n", i++);
//     //     tmp = tmp->next;
//     //     len--;
//     // }
// }
