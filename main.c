/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:33:52 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/21 20:53:27 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	g_exit = 0;

// void start_process(t_main *core)
// {
//     std_read(&core->h);
//     if (strcmp(core->h.retun, "") == 0)
//        return;
//     //print_read(&core->read);
//     tokenize(core);
//     std_exv(core);
//     if(core->h.in_file)
//         unlink(core->h.in_file);
// }

	// static void fork_builde(t_main *core)
	// {
	// 	signal(SIGINT, SIG_IGN);
	// 	signal(SIGQUIT, SIG_IGN);

	// 	// while (1)
	// 	//     start_process(core);
	// }

void std_directory_save(t_main *core)
{
    core->stdin_copy = dup(STDIN_FILENO);
    if (core->stdin_copy == -1)
    {
        perror("dup stdin");
        exit(EXIT_FAILURE);
    }
    core->stdout_copy = dup(STDOUT_FILENO);
    if (core->stdout_copy == -1)
    {
        perror("dup stdout");
        exit(EXIT_FAILURE);
    }
}

int	main(void)
{
	t_main	main;
	//main.env = copy_env();
	//std_directory_save(&main);
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
