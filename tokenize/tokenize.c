/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/11 17:15:29 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO:
implementare il $ prima di tutto cosicché riconosca che quello che segue è
il nome di una variabile d'ambiente e di conseguenza (spiegazione accurata-> chat gpt)
*/
#include "../struct.h"

char	**tokenize(char *input)
{
	t_tokenize	t;

	t.i = 0;
	t.j = 0;
	t.token_count = 0;
	t.tokens = malloc(sizeof(char *) * TOKEN_MAX);
	if (!t.tokens)
		return (NULL);
	while (input[t.i])
	{
		if ((input[t.i] >= 9 && input[t.i] <= 32) || input[t.i] == '|'
			|| input[t.i] == '<' || input[t.i] == '>')
			ft_space_or_operator(&t, input);
		else if (input[t.i] == '\'' || input[t.i] == '\"')
			ft_quote_str(&t, input);
		else
			ft_else_char(&t, input);
		t.i++;
	}
	if (input[t.i] == '\0' && input[--t.i] != ' ')
		ft_last_token(&t);
	return (t.tokens);
}
