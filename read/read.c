/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:24:11 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/19 17:49:24 by ccalabro         ###   ########.fr       */
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

void	v_read(t_main *main)
{
	/*int	i;
	char	**matrix;
	i = 0;
	matrix = NULL*/
	while (1)
	{
		main->inputstr = readline("Minishell > ");
		printf("%s\n", main->inputstr);
		// if (str)
		//     printf("You entered: %s\n", str);
		heredoc(main->inputstr, main);
		tokenize(main->inputstr, main);
		// while(matrix[i])
		// {
		// 	printf("token attuale[%d]: %s\n", i, matrix[i]);
		// 	i++;
		// 	printf("next token[%d]: %s\n", i, matrix[i]);
		// }
		unlink("IN_HEREDOC");
	}
}
