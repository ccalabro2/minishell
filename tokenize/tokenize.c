/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goccia <goccia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/13 16:20:51 by goccia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char	**tokenize(char *str)
{
	char **input;
	int x;
	t_tokenize	t;
	
	x = 0;
	input = pipe_splitter(str);
	while (input[x] != NULL)
	{

		t.i = 0;
		t.j = 0;
		t.token_count = 0;
		t.tokens = malloc(sizeof(char *) * TOKEN_MAX);
		if (!t.tokens)
			return (NULL);
		while (input[x][t.i])
		{
			if ((input[x][t.i] >= 9 && input[x][t.i] <= 32) || input[x][t.i] == '|'
				|| input[x][t.i] == '<' || input[x][t.i] == '>')
				ft_space_or_operator(&t, *input);
			else if (input[x][t.i] == '\'' || input[x][t.i] == '\"')
				ft_quote_str(&t, *input);
			else
				ft_else_char(&t, *input);
			t.i++;
		}
		if (input[x][t.i] == '\0' && input[x][--t.i] != ' ')
			ft_last_token(&t);
		
		x++;
	}
		return (t.tokens);
}
