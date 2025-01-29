/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:23:18 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/29 21:14:36 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO:
-ottimizzare l'operatore < come ho fatto per il maggiore*/
#include "struct.h"

void	ft_space_or_operator(t_tokenize *t, char *input)
{
	if (t->j > 0)
	{
		t->buffer[t->j] = '\0';
		t->tokens[t->token_count] = ft_strdup(t->buffer);
		t->token_count++;
		t->j = 0;
		printf("genera token\n");
		printf("j = %d\n", t->j);
	}
	if (input[t->i] != ' ' && input[t->i] != '\t')
	{
		t->buffer[0] = input[t->i];
//operatori >> e >
		if (input[t->i] == '>')
		{
			t->i = t->i + 1;
			if (input[t->i] == '>')
			{
				t->buffer[1] = '>';
				t->buffer[2] = '\0';
			}
			else
			{
				t->i = t->i - 1;
				t->buffer[1] = '\0';
			}
			t->tokens[t->token_count] = ft_strdup(t->buffer);
			t->token_count++;
			printf("genera token operatore\n");
		}
//operatori << e <
		else if (input[t->i] == '<')
		{
			t->i = t->i + 1;
			if (input[t->i] == '<')
			{
				t->buffer[1] = '<';
				t->buffer[2] = '\0';
			}
			else
			{
				t->i = t->i - 1;
				t->buffer[1] = '\0';
			}
			t->tokens[t->token_count] = ft_strdup(t->buffer);
			t->token_count++;
			printf("genera token operatore\n");
		}
		else
		{
			t->buffer[1] = '\0';
			t->tokens[t->token_count] = ft_strdup(t->buffer);
			t->token_count++;
			printf("genera token operatore\n");
		}
	}
}

void	ft_quote_str(t_tokenize *t, char *input)
{
	t->quote = input[t->i++];
	printf("inizio stringa\n");
	while (input[t->i] && input[t->i] != t->quote)
	{
		t->buffer[t->j] = input[t->i];
		t->j++;
		t->i++;
	}
	printf("fine stringa\n");
	t->buffer[t->j] = '\0';
	t->tokens[t->token_count] = ft_strdup(t->buffer);
	t->token_count++;
	t->j = 0;
}

void	ft_else_char(t_tokenize *t, char *input)
{
	t->buffer[t->j] = input[t->i];
	t->j++;
	printf("j = %d\n", t->j);
}

void	ft_last_token(t_tokenize *t)
{
	t->buffer[t->j] = '\0';
	t->tokens[t->token_count] = ft_strdup(t->buffer);
	t->token_count++;
	t->j = 0;
	printf("last token\n");
	printf("j = %d\n", t->j);
}
