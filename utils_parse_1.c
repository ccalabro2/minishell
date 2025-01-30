/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:08:44 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/30 15:32:45 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

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
