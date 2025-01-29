/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/29 14:50:03 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO:
-accorciare la funzione dividendola in: ft_if_spaziature_o_operatori, ft_if_stringa*/
#include "struct.h"

char	**tokenize(char *input)
{
	/*char	**tokens;
	char	quote;
	char	buffer [TOKEN_MAX];
	int		i;
	int		j;
	int		token_count;*/
	t_tokenize t;
	t.i = 0;
	t.j = 0;
	t.token_count = 0;
	t.tokens = malloc(sizeof(char *) * TOKEN_MAX);
	if (!t.tokens)
		return (NULL);
	while (input[t.i])
	{
		if (/*input[i] == '\t' || input[i] == ' ' */(input[t.i] >= 9 && input[t.i] <= 32) || input[t.i] == '|'
			|| input[t.i] == '<' || input[t.i] == '>')
		{
			if (t.j > 0)
			{
				t.buffer[t.j] = '\0';
				t.tokens[t.token_count] = ft_strdup(t.buffer);
				t.token_count++;
				t.j = 0;
				printf("genera token\n");
				printf("j = %d\n", t.j);
			}


			if (input[t.i] != ' ' && input[t.i] != '\t')/* (input[i] < 9 && input[i] > 32)*/
			{
				t.buffer[0] = input[t.i];
				t.buffer[1] = '\0';
				t.tokens[t.token_count] = ft_strdup(t.buffer);
				t.token_count++;
				printf("genera token operatore\n");
			}
		}


		else if (input[t.i] == '\'' || input[t.i] == '\"')
		{
			t.quote = input[t.i++];
			printf("inizio stringa\n");
			while (input[t.i] && input[t.i] != t.quote)
			{
				t.buffer[t.j] = input[t.i];
				t.j++;
				t.i++;
			}
			printf("fine stringa\n");
			t.buffer[t.j] = '\0';
			t.tokens[t.token_count] = ft_strdup(t.buffer);
			t.token_count++;
			t.j = 0;
		}
		else
		{
			t.buffer[t.j] = input[t.i];
			t.j++;
			printf("j = %d\n", t.j);
		}
		t.i++;
	}


	if (input[t.i] == '\0' && input[--t.i] != ' ' /*input[--i] < 9 && input[--i] > 32*/)
	{
		t.buffer[t.j] = '\0';
		t.tokens[t.token_count] = ft_strdup(t.buffer);
		t.token_count++;
		t.j = 0;
		printf("last token\n");
		printf("j = %d\n", t.j);
	}
	return (t.tokens);
}
