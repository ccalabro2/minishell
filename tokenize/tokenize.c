/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/21 22:12:21 by gd-auria         ###   ########.fr       */
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
void	print_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	//printf("\nCommand: %s\n", cmd->command ? cmd->command : "NULL");
	//printf("Arguments: ");
	if (cmd->args)
	{
		while (cmd->args[i])
		{
			//printf("\"%s\" ", cmd->args[i]);
			i++;
		}
	}
	else
		printf("NULL");
	//printf("\n");
	//printf("Input: %s\n", cmd->input ? cmd->input : "NULL");
	///printf("Output: %s\n", cmd->output ? cmd->output : "NULL");
	//printf("Flag: %d\n", cmd->flag);
	//printf("\n");
}

/* Funzione per allocare memoria per main->fun
- fun e'il tipo t_cmd
*/
void	build_cmdarray(t_main *main)
{
	main->cmdarray = ft_calloc(main->pipe_number + 1, sizeof(t_cmd));
	if (!main->cmdarray)
	{
		printf("Errore: malloc fallita in build_fun\n");
		exit(EXIT_FAILURE);
	}
	// AAA e'una lista ? ... termina con null ? ha prev e next ?
}

/* Riceve una sottostringa e riempie il corrispondente
elemento t_cmd del cmdarray*/
//TODO: implementare con <  > ecc.... AAA spazio
void	parser(char *str, t_cmd *elment_array, int index)
{
	int		i;
	int		k;
	char	**matrix;

	i = 0;
	k = 0;
	matrix = ft_op_split(str, ' ');
	if (!matrix)
	{
		printf("Errore: ft_split ha restituito NULL\n");
		return ;
	}
	//int count = ft_count_words(str, ' ') + 1;
	elment_array->args = malloc(sizeof(char *) * 250);
	if (!elment_array->args)
	{
		printf("Errore: malloc fallita per args\n");
		free(matrix);
		return ;
	}
	// Gestione delle pipe
	if (index > 0)
		elment_array->input = PIPE_IN;
	if (index < elment_array->start->pipe_number - 1)
		elment_array->output = PIPE_OUT;
	while (matrix[i])
	{
		if (ft_strcmp(matrix[i], "<") == 0)
		{
			if (matrix[i + 1])
				elment_array->input = ft_strdup(matrix[++i]);
		}
		else if (ft_strcmp(matrix[i], ">") == 0)
		{
			if (matrix[i + 1])
			{
				elment_array->output = ft_strdup(matrix[++i]);
				elment_array->flag = 1;
			}
		}
		else if (ft_strcmp(matrix[i], ">>") == 0)
		{
			if (matrix[i + 1])
			{
				elment_array->output = ft_strdup(matrix[++i]);
				elment_array->flag = 0;
			}
		}
		else
			elment_array->args[k++] = matrix[i];
		i++;
	}
	elment_array->args[k] = NULL;
	elment_array->command = (elment_array->args[0])
		? elment_array->args[0] : NULL;
	// Liberare la memoria di ft_split
	// for (int j = 0; matrix[j]; j++)
	//     free(matrix[j]);
	// free(matrix);
}

// Funzione principale di tokenizzazione
void	tokenize(char *inputstr, t_main *main)
{
	int		i;
	char	**input_matrix;

	i = 0;
	input_matrix = pipe_splitter(inputstr, main);
	if (!input_matrix)
	{
		printf("Errore: pipe_splitter ha restituito NULL\n");
		return ;
	}
	build_cmdarray(main);
	while (i < main->pipe_number)
	{
		main->cmdarray[i].start = main;
		parser(input_matrix[i], &main->cmdarray[i], i);
		print_cmd(&main->cmdarray[i]);
		i++;
	}
}
