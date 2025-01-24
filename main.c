/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goccia <goccia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:33:52 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/24 16:42:47 by goccia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int main(void)
{
	//t_cmd *cmd;
	char	input[] = "echo 'Hello World' > file.txt | wc";
	char	**tokens = tokenize(input);
	int		i;

	i = 0;
	while (tokens[i])
	{
		printf("token attuale[%d]: %s\n", i, tokens[i]);
		i++;
		printf("next token[%d]: %s\n", i, tokens[i]);
	}
	// cmd = parse(tokens);
	// printf("\nCommand: %s\n", cmd->command);
	// i = 0;
	// while (cmd->args[i]) {
	// 	printf("Arg[%d]: %s\n", i, cmd->args[i]);
	// 	i++;
	// }
	// if (cmd->input)
	// 	printf("Input: %s\n", cmd->input);
	// if (cmd->output)
	// 	printf("Output: %s (flag: %d)\n", cmd->output, cmd->flag);

	// // Libera la memoria
	// i = 0;
	// while (tokens[i]) {
	// 	free(tokens[i]);
	// 	i++;
	// }
	// free(tokens);

	// free(cmd->command);
	// i = 0;
	// while (cmd->args[i]) {
	// 	free(cmd->args[i]);
	// 	i++;
	// }
	// free(cmd->args);
	// free(cmd->input);
	// free(cmd->output);
	// free(cmd);
	return (0);
}
