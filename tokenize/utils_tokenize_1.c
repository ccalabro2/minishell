/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenize_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:23:18 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/19 18:10:31 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

// void	ft_space_or_operator(t_tokenize *t, char *input)
// {
// 	if (t->j > 0)
// 	{
// 		t->buffer[t->j] = '\0';
// 		t->tokens[t->token_count] = ft_strdup(t->buffer);
// 		t->token_count++;
// 		t->j = 0;
// 		printf("genera token\n");
// 		printf("j = %d\n", t->j);
// 	}
// 	if (input[t->i] != ' ' && input[t->i] != '\t')
// 	{
// 		t->buffer[0] = input[t->i];
// 		if (input[t->i] == '>')
// 			ft_output_redirect(t, input);
// 		else if (input[t->i] == '<')
// 			ft_input_redirect(t, input);
// 		else
// 		{
// 			t->buffer[1] = '\0';
// 			t->tokens[t->token_count] = ft_strdup(t->buffer);
// 			t->token_count++;
// 			printf("genera token operatore\n");
// 		}
// 	}
// }

// void	ft_quote_str(t_tokenize *t, char *input)
// {
// 	t->quote = input[t->i++];
// 	printf("inizio stringa\n");
// 	while (input[t->i] && input[t->i] != t->quote)
// 	{
// 		t->buffer[t->j] = input[t->i];
// 		t->j++;
// 		t->i++;
// 	}
// 	/*	if per interrompere quando non chiudiamo le virgolette
// 		-trovare il modo per uscire dato che non puó...
//		...returnare nulla essendo void
// 	if(!input[t->i])
// 		return;*/
// 	printf("fine stringa\n");
// 	t->buffer[t->j] = '\0';
// 	t->tokens[t->token_count] = ft_strdup(t->buffer);
// 	t->token_count++;
// 	t->j = 0;
// }

// void	ft_else_char(t_tokenize *t, char *input)
// {
// 	t->buffer[t->j] = input[t->i];
// 	t->j++;
// 	printf("j = %d\n", t->j);
// }

// void	ft_last_token(t_tokenize *t)
// {
// 	t->buffer[t->j] = '\0';
// 	t->tokens[t->token_count] = ft_strdup(t->buffer);
// 	t->token_count++;
// 	t->j = 0;
// 	printf("last token\n");
// 	printf("j = %d\n", t->j);
// }

void	short_tokenize(char **matrix, t_cmd *element_array)
{
	int i;
	int k;

	k = 0;
	i = 0;
	if (ft_strcmp(matrix[i], "<") == 0)
	{
		if (matrix[i + 1])
			element_array->input = ft_strdup(matrix[++i]);
	}
	else if (ft_strcmp(matrix[i], ">") == 0)
	{
		if (matrix[i + 1])
		{
			element_array->output = ft_strdup(matrix[++i]);
			element_array->flag = 1;
		}
	}
	else if (ft_strcmp(matrix[i], ">>") == 0)
		for_short_tokenize(element_array, i, matrix);
	else
		element_array->args[k++] = matrix[i];
	i++;
}

void	for_short_tokenize(t_cmd *element_array, int i, char **matrix)
{
	if (matrix[i + 1])
	{
		element_array->output = ft_strdup(matrix[++i]);
		element_array->flag = 0;
	}
}
