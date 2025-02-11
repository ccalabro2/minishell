/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:24:11 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/11 15:40:31 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../struct.h"


void	here_doc_open(char *del)
{
	char	*here_doc_line;
	char	*new;
	int		fd;

	new = ft_strdup("");
	here_doc_line = ft_strdup("");
	fd = open("IN_HEREDOC", O_WRONLY|O_CREAT|O_APPEND, 0644);
	//funzione per creare file e passaggi
	while(1)
	{
		here_doc_line = readline(" |heredoc > ");
		// stampa nel file input
		if(ft_strcmp(here_doc_line, del) == 0)
			break;

		new = expand_variables(here_doc_line, true ); //funzione di chat(va cambiata)
		write(fd, new, ft_strlen(here_doc_line));
		write(fd, "\n", 1);
		// QUANDO HAI LETTO SCRIVI NEL FILE QUELLO CHE HAI SCRITTO IN HEREDOC

	}
}

int here_doc(char *str)
{
	int i = 0;
	int k = 0;
	int f = 0;

	int boll = 1;
	char del[250] = {0};  // Inizializza l'array
	char retun[250] = {0};

	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<') {
			i += 2;
			while (str[i] && str[i] <= 32)  // Salta spazi
				i++;
			k = 0;  // Reset per riempire correttamente del[]
			while (str[i] && str[i] > 32 && k < 249)
			{  // Legge il delimitatore
				while (str[i] == '\'' || str[i] == '\"')
					i++;
				del[k++] = str[i++];
			}
			del[k] = '\0';  // Termina la stringa
			if (ft_strlen(del) < 1) {
				printf("minishell: syntax error near unexpected token `newline`\n");
				return 1;  // Errore di sintassi
			}
			boll = 0;
			continue;  // Salta il resto del loop e evita di copiare `<< delimiter` in retun[]
		}
		retun[f++] = str[i++];
	}
	retun[f] = '\0';
	//printf("Stringa finale senza heredoc: %s\n", retun);
	if (boll == 0)
		here_doc_open(del);
	return boll;
}

void v_read()
{
	//t_read->input = strdup("");
	char *str = readline("Minishell > ");
	// if (str)
	//     printf("You entered: %s\n", str);
	here_doc(str);
	unlink("IN_HEREDOC");
}
