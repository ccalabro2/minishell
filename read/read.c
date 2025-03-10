/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:24:11 by gd-auria          #+#    #+#             */
/*   Updated: 2025/03/01 12:53:22 by ccalabro         ###   ########.fr       */
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
		return (printf("open"), exit(EXIT_FAILURE));
	while (1)
	{
		here_doc_line = readline(" |heredoc > ");
		if (!here_doc_line)
			break ;
		if (ft_strcmp(here_doc_line, del) == 0)
		{
			free(here_doc_line);
			break ;
		}
		expanded_line = expand_variables(here_doc_line, true, true);
		write(fd, expanded_line, ft_strlen(expanded_line));
		write(fd, "\n", 1);
	}
	close(fd);
}

int	heredoc(char *str, t_main *main)
{
	inizialize_heredoc(str, main);
	while (str[main->h.i])
	{
		if (str[main->h.i] == '<' && str[main->h.i + 1] == '<')
		{
			main->h.i += 2;
			while (str[main->h.i] && str[main->h.i] <= 32)
				main->h.i++;
			main->h.k = 0;
			while (str[main->h.i] && str[main->h.i] > 32 && main->h.k < 249)
			{
				while (str[main->h.i] == '\"' || str[main->h.i] == '\'')
					main->h.i++;
				main->h.del[main->h.k++] = str[main->h.i++];
			}
			main->h.del[main->h.k] = '\0';
			if (ft_strlen(main->h.del) < 1)
				return (printf("Minishell: synt error near unex tok\n"), 1);
			main->h.boll = 0;
			continue ;
		}
		main->h.retun[main->h.f++] = str[main->h.i++];
	}
	bob(main);
	return (main->h.boll);
}

void	generate_pipematrix(int number_pipe, t_main *main)
{
	int	i;

	main->pipematrix = (int **)malloc((number_pipe - 1) * sizeof(int *));
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

void	v_read(t_main *main, char **env)
{
	ft_memset(main, 0, sizeof(t_main));
	while (1)
	{
		prompt(main, env);
		if (main->inputstr == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (ft_strlen(main->inputstr) == 0 || ft_spn(main->inputstr, " \t\n\r")
			== ft_strlen(main->inputstr))
		{
			free(main->inputstr);
			continue ;
		}
		call_heredoc_nd_ctrl_d(main);
		if (ft_strcmp(main->inputstr, "") == 0)
		{
			if (access("IN_HEREDOC", F_OK) == 0)
				unlink("IN_HEREDOC");
			free(main->inputstr);
			continue ;
		}
		last_fun(main);
	}
}
