/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/18 17:04:52 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"
// char **tokenize(char *str, t_main *main)
// {
//     char **input;
//     int x;
//     t_tokenize t;

//     x = 0;
//     input = pipe_splitter(str, main);
//     t.token_count = 0;
//     t.tokens = malloc(sizeof(char *) * TOKEN_MAX);
//     if (!t.tokens)
//         return (NULL);

//     while (input[x] != NULL)
//     {
//         // Salta segmenti vuoti o composti solo da spazi
//         if (input[x][0] == '\0' || is_all_whitespace(input[x]))
//         {
//             x++;
//             continue;
//         }
//         t.i = 0;
//         // Assumendo che t.j sia l'indice nel buffer del token corrente:
//         t.j = 0;
//         while (input[x][t.i])
//         {
//             if ((input[x][t.i] >= 9 && input[x][t.i] <= 32)
//                 || input[x][t.i] == '<' || input[x][t.i] == '>')
//             {
//                 /* Se il buffer contiene dati, salva il token corrente
//                    e poi gestisci l'operatore/spazio */
//                 if (t.j > 0)
//                     ft_last_token(&t);
//                 ft_space_or_operator(&t, input[x]);
//             }
//             else if (input[x][t.i] == '\'' || input[x][t.i] == '\"')
//                 ft_quote_str(&t, input[x]);
//             else
//                 ft_else_char(&t, input[x]);
//             t.i++;
//         }
//         /* Alla fine del segmento, se nel buffer c'è un token in costruzione,
//            chiamalo per salvare il token corrente (es. "-l") */
//         if (t.j > 0)
//             ft_last_token(&t);
//         x++;
//     }
//     return (t.tokens);
// }

// Funzione per stampare il contenuto della struct t_cmd
void print_cmd(t_cmd *cmd)
{
    int i = 0;

    printf("Command: %s\n", cmd->command ? cmd->command : "NULL");
    printf("Arguments: ");
    if (cmd->args)
    {
        while (cmd->args[i])
        {
            printf("\"%s\" ", cmd->args[i]);
            i++;
        }
    }
    else
        printf("NULL");
    printf("\n");
    printf("Input: %s\n", cmd->input ? cmd->input : "NULL");
    printf("Output: %s\n", cmd->output ? cmd->output : "NULL");
    printf("Flag: %d\n", cmd->flag);
}

// Funzione per allocare memoria per main->fun
void build_fun(t_main *main)
{
    main->fun = ft_calloc(main->pipe_number + 1, sizeof(t_cmd));
    if (!main->fun)
    {
        printf("Errore: malloc fallita in build_fun\n");
        exit(EXIT_FAILURE);
    }
}

// Parsing della stringa in una struttura t_cmd
void sub_string(char *str, t_cmd *fun, int index)
{
    int i = 0;
    int k = 0;
    char **matrix = ft_split(str, ' ');

    if (!matrix)
    {
        printf("Errore: ft_split ha restituito NULL\n");
        return;
    }
    //int count = ft_count_words(str, ' ') + 1;
    fun->args = malloc(sizeof(char *) * 250);
    if (!fun->args)
    {
        printf("Errore: malloc fallita per args\n");
        free(matrix);
        return;
    }
    // Gestione delle pipe
    if (index > 0)
        fun->input = PIPE_IN;
    if (index < fun->start->pipe_number - 1)
        fun->output = PIPE_OUT;

    while (matrix[i])
    {
        if (ft_strcmp(matrix[i], "<") == 0)
        {
            if (matrix[i + 1])
                fun->input = ft_strdup(matrix[++i]);
        }
        else if (ft_strcmp(matrix[i], ">") == 0)
        {
            if (matrix[i + 1])
            {
                fun->output = ft_strdup(matrix[++i]);
                fun->flag = 1;
            }
        }
        else if (ft_strcmp(matrix[i], ">>") == 0)
        {
            if (matrix[i + 1])
            {
                fun->output = ft_strdup(matrix[++i]);
                fun->flag = 0;
            }
        }
        else
            fun->args[k++] = matrix[i];

        i++;
    }
    fun->args[k] = NULL;
    fun->command = (fun->args[0]) ? fun->args[0] : NULL;
    // Liberare la memoria di ft_split
    // for (int j = 0; matrix[j]; j++)
    //     free(matrix[j]);
    // free(matrix);
}


// Funzione principale di tokenizzazione
void tokenize(char *str, t_main *main)
{
    char **input;
    int i = 0;

    input = pipe_splitter(str, main);
    if (!input)
    {
        printf("Errore: pipe_splitter ha restituito NULL\n");
        return;
    }
    build_fun(main);
    while (i < main->pipe_number)
    {
        main->fun[i].start = main;
        sub_string(input[i], &main->fun[i], i);
        print_cmd(&main->fun[i]);
        i++;
    }
}
