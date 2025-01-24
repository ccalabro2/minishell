/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goccia <goccia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/24 16:44:17 by goccia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

char	**tokenize(char *input)
{
	char	**tokens;
	char	quote;
	char	buffer [TOKEN_MAX];
	int		i;
	int		j;
	int		token_count;

	i = 0;
	j = 0;
	token_count = 0;
	tokens = malloc(sizeof(char *) * TOKEN_MAX);
	if (!tokens)
		return (NULL);
	while (input[i])
	{
		if (/*input[i] == '\t' || input[i] == ' ' */(input[i] >= 9 && input[i] <= 32) || input[i] == '|'
			|| input[i] == '<' || input[i] == '>')
		{
			if (j > 0)
			{
				buffer[j] = '\0';
				tokens[token_count] = ft_strdup(buffer);
				token_count++;
				j = 0;
				printf("genera token\n");
				printf("j = %d\n", j);
			}
			if (input[i] != ' ' && input[i] != '\t')/* (input[i] < 9 && input[i] > 32)*/
			{
				buffer[0] = input[i];
				buffer[1] = '\0';
				tokens[token_count] = ft_strdup(buffer);
				token_count++;
				printf("genera token operatore\n");
			}
		}
		else if (input[i] == '\'' || input[i] == '\"')
		{
			quote = input[i++];
			printf("inizio stringa\n");
			while (input[i] && input[i] != quote)
			{
				buffer[j] = input[i];
				j++;
				i++;
			}
			printf("fine stringa\n");
			buffer[j] = '\0';
			tokens[token_count] = ft_strdup(buffer);
			token_count++;
			j = 0;
		}
		else
		{
			buffer[j] = input[i];
			j++;
			printf("j = %d\n", j);
		}
		i++;
	}
	if (input[i] == '\0' && input[--i] != ' ' /*input[--i] < 9 && input[--i] > 32*/)
	{
		buffer[j] = '\0';
		tokens[token_count] = ft_strdup(buffer);
		token_count++;
		j = 0;
		printf("last token\n");
		printf("j = %d\n", j);
	}
	return (tokens);
}