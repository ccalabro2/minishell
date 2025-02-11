/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:08:44 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/11 17:19:48 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	ft_input_redirect_parse(t_cmd *cmd, char **tokens, int i)
{
	if (*(tokens[i] + 1))
	{
		if (tokens[i])
		{
			cmd->input = strdup(tokens[i]);
			cmd->flag = 1;
		}
	}
	else
	{
		if (tokens[i])
			cmd->input = strdup(tokens[i]);
	}
}

void	ft_output_redirect_parse(t_cmd *cmd, char **tokens, int i)
{
	if (*(tokens[i] + 1))
	{
		if (tokens[i])
		{
			cmd->input = strdup(tokens[i]);
			cmd->flag = 1;
		}
	}
	else
	{
		if (tokens[i])
			cmd->input = strdup(tokens[i]);
	}
}

void	init(t_cmd *cmd)
{
	cmd->command = NULL;
	cmd->args = malloc(sizeof(char *) * TOKEN_MAX);
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->flag = 0;
	if (!cmd)
		return ;
}
