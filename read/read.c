/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:24:11 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/20 23:23:57 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	here_doc_open(char *del)
{
	char	*here_doc_line;
	char	*new;
	char	*expanded_line;
	int		fd;

	new = ft_strdup("");
	printf("%s\n", new);
	fd = open("IN_HEREDOC", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	while (1)
	{
		here_doc_line = readline(" |heredoc > ");
		if (!here_doc_line) // Controlla EOF (Ctrl+D)
			break ;
		// Se la riga è il delimitatore, esce
		if (ft_strcmp(here_doc_line, del) == 0)
		{
			free(here_doc_line);
			break ;
		}
		// Espande variabili
		expanded_line = expand_variables(here_doc_line, true, true);
		// Scrive la riga espansa nel file
		write(fd, expanded_line, ft_strlen(expanded_line));
		write(fd, "\n", 1);
		// Libera memoria
		//free(here_doc_line);
		//free(expanded_line);
	}
	close(fd);
}

int	heredoc(char *str, t_main *main)
{
	main->h.f = 0;
	main->h.k = 0;
	main->h.i = 0;
	main->h.boll = 1;
	main->h.retun = str; // AAA: da vedere in un secondo momento
	ft_memset(main->h.del, 0, 250);
	//ft_memset(main->h.retun, 0, 250);
	while (str[main->h.i])
	{
		if (str[main->h.i] == '<' && str[main->h.i + 1] == '<')
		{
			main->h.i += 2;
			while (str[main->h.i] && str[main->h.i] <= 32) // Salta spazi
				main->h.i++;
			main->h.k = 0;// Reset per riempire correttamente del[]
			while (str[main->h.i] && str[main->h.i] > 32 && main->h.k < 249)
			{
				// Legge il delimitatore
				while (str[main->h.i] == '\"' || str[main->h.i] == '\'')
					main->h.i++;
				main->h.del[main->h.k++] = str[main->h.i++];
			}
			main->h.del[main->h.k] = '\0';// Termina la stringa
			if (ft_strlen(main->h.del) < 1)
			{
				printf("minishell: syntax error near unexpected token `newline`\n");
				return (1);// Errore di sintassi
			}
			main->h.boll = 0;
			// Salta il resto del loop e evita di copiare `<< delimiter` in retun[]
			continue ;
		}
		main->h.retun[main->h.f++] = str[main->h.i++];
	}
	main->h.retun[main->h.f] = '\0';
	if (main->h.boll == 0)
		here_doc_open(main->h.del);
	return (main->h.boll);
}


/*
    lettura ======== scrittura
		0               1
	int canale[2];
	cnale[0] e'léstremita' di lettura
	canale[1] estremitá di scrittura

*/
void	generate_pipematrix(int number_pipe, t_main *main)
{
	///perché il numero di pie e'sempre +1
	int	i;

	main->pipematrix = (int **)malloc((number_pipe - 1)* sizeof(int *));

	i = 0;
	while (i < number_pipe)
	{
		main->pipematrix[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < number_pipe)
	{
		pipe(main->pipematrix[i]);
		i++;
	}
}


void	v_read(t_main *main)
{
	/*int	i;
	char	**matrix;
	i = 0;
	matrix = NULL*/
	while (1)
	{
		init_signals();
		main->inputstr = readline("Minishell > ");
		handle_ctrl_d(main->inputstr);
		printf("%s\n", main->inputstr);
		// if (str)
		//     printf("You entered: %s\n", str);
		heredoc(main->inputstr, main);
		tokenize(main->inputstr, main);

		printf("ecco il numero delle pipe:  %d\n" , main->pipe_number);
		if (main->pipe_number > 1)
		{

			printf("Hey! Stai per entrare in pipex\n");

			generate_pipematrix(main->pipe_number, main);
			pipex(main->cmdarray, main->pipe_number, main->pipematrix, main->env);

		}



		if (main->inputstr)                        // Aggiunge alla cronologia se non vuoto
			add_history(main->inputstr);
		// while(matrix[i])
		// {
		// 	printf("token attuale[%d]: %s\n", i, matrix[i]);
		// 	i++;
		// 	printf("next token[%d]: %s\n", i, matrix[i]);
		// }
		free(main->inputstr);
		unlink("IN_HEREDOC");
	}
}
