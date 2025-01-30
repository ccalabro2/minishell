/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:36:40 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/30 15:24:43 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO:
-gestire anche le pipe
-accorciare la funzione dividendola in: (es)ft_operator per i primi 3 if e ft_cdm_args
*/
#include "struct.h"

t_cmd	parse(char **tokens)
{
	t_cmd	cmd;
	int		i;
	int		arg_index;

	i = 0;
	arg_index = 0;
	init(&cmd);
	while (tokens[i])
	{
		printf("(siamo in parse)TOKEN: %s\n", tokens[i]);
		if (*tokens[i] == '<')
			ft_output_redirect_parse(&cmd, tokens, i);
		else if (*tokens[i] == '>')
			ft_input_redirect_parse(&cmd, tokens, i);
		else if (!cmd.command)
			cmd.command = strdup(tokens[i]);
		else
		{
			cmd.args[arg_index] = strdup(tokens[i]);
			arg_index++;
		}
		i++;
	}
	cmd.args[arg_index] = NULL;
	return (cmd);
}
