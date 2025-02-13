/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goccia <goccia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:24:11 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/13 16:07:55 by goccia           ###   ########.fr       */
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

int	heredoc(char *str)
{
	t_heredoc	h;

	h.f = 0;
	h.k= 0;
	h.i = 0;
	h.boll = 1;
	ft_memset(h.del, 0, 250);
	ft_memset(h.retun, 0, 250);
	while (str[h.i])
	{
		if (str[h.i] == '<' && str[h.i + 1] == '<')
		{
			h.i += 2;
			while (str[h.i] && str[h.i] <= 32)  // Salta spazi
				h.i++;
			h.k = 0;  // Reset per riempire correttamente del[]
			while (str[h.i] && str[h.i] > 32 && h.k < 249)
			{  // Legge il delimitatore
				while (str[h.i] == '\"' || str[h.i] == '\'')
					h.i++;
				h.del[h.k++] = str[h.i++];
			}
			h.del[h.k] = '\0';// Termina la stringa

			if (ft_strlen(h.del) < 1)
			{
				printf("minishell: syntax error near unexpected token `newline`\n");
				return 1;  // Errore di sintassi
			}
			h.boll = 0;
			continue;  // Salta il resto del loop e evita di copiare `<< delimiter` in retun[]
		}
		h.retun[h.f++] = str[h.i++];
	}
	h.retun[h.f] = '\0';
	if (h.boll == 0)
		here_doc_open(h.del);
	return h.boll;
}

void v_read()
{
	//t_read->input = strdup("");
	char *str = readline("Minishell > ");
	// if (str)
	//     printf("You entered: %s\n", str);
	heredoc(str);
	unlink("IN_HEREDOC");
}
