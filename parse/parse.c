/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:36:40 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/11 17:17:06 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO:
-gestire anche le pipe
*/
#include "../struct.h"

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
			ft_input_redirect_parse(&cmd, tokens, i);
		else if (*tokens[i] == '>')
			ft_output_redirect_parse(&cmd, tokens, i);
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
