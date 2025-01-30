/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenize_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:29:52 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/30 15:38:34 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_output_redirect(t_tokenize *t, char *input)
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

void	ft_input_redirect(t_tokenize *t, char *input)
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
