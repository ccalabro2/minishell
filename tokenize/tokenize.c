/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/14 16:53:20 by gd-auria         ###   ########.fr       */
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
    main->fun = malloc((main->pipe_number * sizeof(t_cmd)) + 1);
    if (!main->fun)
    {
        fprintf(stderr, "Errore: malloc fallita in build_fun\n");
        exit(EXIT_FAILURE);
    }
}

// Parsing della stringa in una struttura t_cmd
void sub_string(char *str, t_cmd *fun)
{
    int i = 0;
    int k = 0;
    char **matrix = ft_split(str, ' ');

    if (!matrix)
    {
        fprintf(stderr, "Errore: ft_split ha restituito NULL\n");
        return;
    }

    // Allocare memoria per args
    fun->args = malloc(sizeof(char *) * 100); // 100 argomenti massimo, cambiare se necessario
    if (!fun->args)
    {
        fprintf(stderr, "Errore: malloc fallita per args\n");
        return;
    }

    while (matrix[i])
    {
        if (strcmp(matrix[i], "<") == 0 && matrix[i + 1])
            fun->input = matrix[++i];
        else if (strcmp(matrix[i], ">") == 0 && matrix[i + 1])
        {
            fun->output = matrix[++i];
            fun->flag = 1;
        }
        else if (strcmp(matrix[i], ">>") == 0 && matrix[i + 1])
        {
            fun->output = matrix[++i];
            fun->flag = 0;
        }
        else
            fun->args[k++] = matrix[i];
        i++;
    }
    if (fun->args[0])
        fun->command = fun->args[0];
    fun->args[k] = NULL; // Terminare la lista degli argomenti
}

// Funzione principale di tokenizzazione
void tokenize(char *str, t_main *main)
{
    char **input;
    int i = 0;

    input = pipe_splitter(str, main);
    if (!input)
    {
        fprintf(stderr, "Errore: pipe_splitter ha restituito NULL\n");
        return;
    }

    build_fun(main);

    while (i < main->pipe_number)
    {
        sub_string(input[i], &main->fun[i]);
        print_cmd(&main->fun[i]);
        i++; // IMPORTANTE: Incremento del contatore per evitare loop infinito
    }
}