/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenize_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:29:52 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/14 17:01:48 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

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

int is_all_whitespace(const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return 0;  // Ha almeno un carattere non di spazio
        i++;
    }
    return 1;  // È composto solo da spazi
}
