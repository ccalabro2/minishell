/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/28 14:11:30 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO:
-accorciare la funzione dividendola in: ft_if_spaziature_o_operatori, ft_if_stringa*/
#include "struct.h"

char	**tokenize(char *input)
{
	char	**tokens;
	char	buffer[TOKEN_MAX];
	int		i;
	int		j;

	i = 0;
	j = 0;
	tokens = malloc(sizeof(char *) * TOKEN_MAX);
	if (!tokens)
		return (NULL);
	while (input[i])
	{
		if (/*input[i] == '\t' || input[i] == ' ' */(input[i] >= 9 && input[i] <= 32) || input[i] == '|'
			|| input[i] == '<' || input[i] == '>')
		{
			if_is_io_redirection(input, tokens);
			if_is_space_tab(input, tokens);
		}
		else if (input[i] == '\'' || input[i] == '\"')
			if_is_quote(input, tokens);
		else
		{
			buffer[j] = input[i];
			j++;
		}
		i++;
	}
	if (input[i] == '\0' && input[--i] != ' ' /*input[--i] < 9 && input[--i] > 32*/)
		if_is_null(input, tokens, buffer);
	return (tokens);
}
