/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:36:40 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/23 18:37:52 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_cmd	*parse(char **tokens)
{
	t_cmd	*cmd;
	int		i;
	int		arg_index;

	cmd = NULL;
	i = 0;
	arg_index = 0;
	init(cmd);
	while (tokens[i])
	{
		if (strcmp(tokens[i], "<") == 0)
		{
			i++;
			if (tokens[i])
				cmd->input = strdup(tokens[i]);
		}
		else if (strcmp(tokens[i], ">") == 0)
		{
			i++;
			if (tokens[i])
				cmd->output = strdup(tokens[i]);
		}
		else if (strcmp(tokens[i], ">>") == 0)
		{
			i++;
			if (tokens[i])
			{
				cmd->output = strdup(tokens[i]);
				cmd->flag = 1;
			}
		}
		else if (!cmd->command)
			cmd->command = strdup(tokens[i]);
		else
		{
			cmd->args[arg_index] = strdup(tokens[i]);
			arg_index++;
		}
		i++;
	}
	cmd->args[arg_index] = NULL;
	return (cmd);
}
