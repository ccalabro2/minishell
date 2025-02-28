/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:41 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/28 12:03:37 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

extern char	**environ;

char	*find_path(t_exec_manager *tools)
{
	char	**split_path;
	char	*candidate_path;
	char	*joined_path;
	char	*path_env;
	int		i;

	candidate_path = NULL;
	joined_path = NULL;
	path_env = getenv("PATH");
	i = 0;
	if (!tools->cmd || !tools->cmd->args || !tools->cmd->args[0] || !path_env)
		return (NULL);
	split_path = ft_split(path_env, ':');
	if (!split_path)
		return (NULL);
	while (split_path[i])
	{
		joined_path = ft_strjoin(split_path[i], "/");
		if (!joined_path)
			break ;
		candidate_path = ft_strjoin(joined_path, tools->cmd->args[0]);
		free(joined_path);
		if (!candidate_path)
			break ;
		if (access(candidate_path, X_OK) == 0)
			break ;
		free(candidate_path);
		candidate_path = NULL;
		i++;
	}
	return (free_matrix(split_path), candidate_path);
}

void	redirect_input(t_exec_manager *tools)
{
	int	in_fd;

	in_fd = -1;
	if (tools->cmd->input)
	{
		if (strcmp(tools->cmd->input, PIPE_IN) == 0 && tools->pipe_std_in >= 0)
			in_fd = tools->pipe_std_in;
		else
		{
			in_fd = open(tools->cmd->input, O_RDONLY);
			if (in_fd == -1)
				return (fprintf(stderr, "Err open inputf"), exit(EXIT_FAILURE));
		}
		if (dup2(in_fd, STDIN_FILENO) == -1)
		{
			perror("Error duplicating stdin");
			if (in_fd >= 0)
				close(in_fd);
			exit(EXIT_FAILURE);
		}
		if (in_fd >= 0)
			close(in_fd);
	}
}

static void	re_out_short(t_exec_manager *tools, int *out_fd)
{
	if (tools->cmd->flag)
		(*out_fd) = open(tools->cmd->output, O_WRONLY
				| O_CREAT | O_APPEND, 0644);
	else
		(*out_fd) = open(tools->cmd->output, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	if ((*out_fd) == -1)
		return (fprintf(stderr, "Err open outfile"), exit(EXIT_FAILURE));
}

void	redirect_output(t_exec_manager *tools)
{
	int	out_fd;

	out_fd = -1;
	if (tools->cmd->output)
	{
		if (strcmp(tools->cmd->output, PIPE_OUT) == 0
			&& tools->pipe_std_out >= 0)
			out_fd = tools->pipe_std_out;
		else
		{
			re_out_short(tools, &out_fd);
		}
		if (dup2(out_fd, STDOUT_FILENO) == -1)
		{
			perror("Error duplicating stdout");
			if (out_fd >= 0)
				close(out_fd);
			exit(EXIT_FAILURE);
		}
		if (out_fd >= 0)
			close(out_fd);
	}
}

void	exe_func(t_exec_manager *tools)
{
	char	*path;
	int		stat;

	if (access(tools->cmd->command, X_OK) == 0)
		path = tools->cmd->command;
	else
		path = find_path(tools);
	if (!path)
	{
		fprintf(stderr, "Command not found: %s\n", tools->cmd->command);
		exit(EXIT_FAILURE);
	}
	redirect_input(tools);
	redirect_output(tools);
	stat = execve(path, tools->cmd->args, environ);
	fprintf(stderr, "%d\n", stat);
	if (stat == -1)
	{
		perror("execve");
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);
}
