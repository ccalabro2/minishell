/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:33:52 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/14 15:50:06 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int main()
{
	t_main	main;
	v_read(&main);
}

// /*
// int	main(int argc, char **argv)
// {
// 	t_cmd	cmd;
// 	char	**tokens = tokenize(argv[1]);
// 	int		i;

// 	if (argc != 2)
// 		return (0);
// 	//char	input[] = "echo | 'Hello World' > file.txt > | << duce | wc" |||;
// 	//int		j;
// 	i = 0;
// 	/*while (tokens[i])
// 	{
// 		printf("token attuale[%d]: %s\n", i, tokens[i]);
// 		i++;
// 		printf("next token[%d]: %s\n", i, tokens[i]);
// 	}*/
// 	cmd = parse(tokens);
// 	// printf("\nCommand: %s\n", cmd->command);
// 	// j = 0;
// 	// while (cmd->args[j])
// 	// {
// 	// 	printf("Arg[%d]: %s\n", j, cmd->args[j]);
// 	// 	j++;
// 	//  }
// 	// if (cmd->input)
// 	// 	printf("Input: %s\n", cmd->input);
// 	// if (cmd->output)
// 	// 	printf("Output: %s (flag: %d)\n", cmd->output, cmd->flag);

// 	// Libera la memoria
// 	// i = 0;
// 	// while (tokens[i]) {
// 	// 	free(tokens[i]);
// 	// 	i++;
// 	// }
// 	// free(tokens);

// 	// free(cmd->command);
// 	// i = 0;
// 	// while (cmd->args[i]) {
// 	// 	free(cmd->args[i]);
// 	// 	i++;
// 	// }
// 	// free(cmd->args);
// 	// free(cmd->input);
// 	// free(cmd->output);
// 	// free(cmd);
// 	return (0);
// }*
