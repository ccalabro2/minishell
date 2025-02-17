/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:24:11 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/14 16:34:41 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	here_doc_open(char *del)
{
	char	*here_doc_line;
	char	*new;
	int		fd;

	new = ft_strdup("");
	printf("%s\n", new);
	fd = open("IN_HEREDOC", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("open");
		return;
	}
	while (1)
	{
		here_doc_line = readline(" |heredoc > ");
		if (!here_doc_line) // Controlla EOF (Ctrl+D)
			break;
		if (ft_strcmp(here_doc_line, del) == 0) // Se la riga è il delimitatore, esce
		{
			free(here_doc_line);
			break;
		}
		// Espande variabili
		char *expanded_line = expand_variables(here_doc_line, true, true);
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
	main->h.k= 0;
	main->h.i = 0;
	main->h.boll = 1;
	ft_memset(main->h.del, 0, 250);
	//ft_memset(main->h.retun, 0, 250);
	while (str[main->h.i])
	{
		if (str[main->h.i] == '<' && str[main->h.i + 1] == '<')
		{
			main->h.i += 2;
			while (str[main->h.i] && str[main->h.i] <= 32)  // Salta spazi
				main->h.i++;
			main->h.k = 0;  // Reset per riempire correttamente del[]
			while (str[main->h.i] && str[main->h.i] > 32 && main->h.k < 249)
			{  // Legge il delimitatore
				while (str[main->h.i] == '\"' || str[main->h.i] == '\'')
					main->h.i++;
				main->h.del[main->h.k++] = str[main->h.i++];
			}
			main->h.del[main->h.k] = '\0';// Termina la stringa

			if (ft_strlen(main->h.del) < 1)
			{
				printf("minishell: syntax error near unexpected token `newline`\n");
				return 1;  // Errore di sintassi
			}
			main->h.boll = 0;
			continue;  // Salta il resto del loop e evita di copiare `<< delimiter` in retun[]
		}
		main->h.retun[main->h.f++] = str[main->h.i++];
	}
	main->h.retun[main->h.f] = '\0';
	if (main->h.boll == 0)
		here_doc_open(main->h.del);
	return main->h.boll;
}

void v_read(t_main *main)
{
	//int i = 0;
	//char **matrix = NULL;
	main->h.retun = readline("Minishell > ");
	printf("%s\n", main->h.retun);
	// if (str)
	//     printf("You entered: %s\n", str);
	heredoc(main->h.retun, main);
	tokenize(main->h.retun, main);
	// while(matrix[i])
	// {
		
	// 	printf("token attuale[%d]: %s\n", i, matrix[i]);
	// 	i++;
 	// 	printf("next token[%d]: %s\n", i, matrix[i]);
 	// }
	unlink("IN_HEREDOC");
}
