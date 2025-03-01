/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:41 by fluzi             #+#    #+#             */
/*   Updated: 2025/03/01 16:17:46 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

extern char	**environ;

char	*find_path(t_exec_manager *tools)
{
	t_f_path	path;

	inizialize_path(&path);
	if (!tools->cmd || !tools->cmd->args || !tools->cmd->args[0]
		|| !path.path_env)
		return (NULL);
	path.split = ft_split(path.path_env, ':');
	if (!path.split)
		return (NULL);
	while (path.split[path.i])
	{
		path.joined = ft_strjoin(path.split[path.i], "/");
		if (!path.joined)
			break ;
		path.candidate = ft_strjoin(path.joined, tools->cmd->args[0]);
		free(path.joined);
		if (!path.candidate)
			break ;
		if (access(path.candidate, X_OK) == 0)
			break ;
		free(path.candidate);
		path.candidate = NULL;
		path.i++;
	}
	return (free_matrix(path.split), path.candidate);
}

void	redirect_input(t_exec_manager *tools)
{
	int	in_fd;

	in_fd = -1;
	if (tools->cmd->input)
	{
		if (ft_strcmp(tools->cmd->input, PIPE_IN)
			== 0 && tools->pipe_std_in >= 0)
			in_fd = tools->pipe_std_in;
		else
		{
			in_fd = open(tools->cmd->input, O_RDONLY);
			if (in_fd == -1)
				return (printf("Err open inputf"), exit(EXIT_FAILURE));
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
		return (printf("Err open outfile\n"), exit(EXIT_FAILURE));
}

void	redirect_output(t_exec_manager *tools)
{
	int	out_fd;

	out_fd = -1;
	if (tools->cmd->output)
	{
		if (ft_strcmp(tools->cmd->output, PIPE_OUT) == 0
			&& tools->pipe_std_out >= 0)
			out_fd = tools->pipe_std_out;
		else
		{
			re_out_short(tools, &out_fd);
		}
		if (dup2(out_fd, STDOUT_FILENO) == -1)
		{
			perror("Error duplicating stdout\n");
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
		printf("Command not found: %s\n", tools->cmd->command);
		exit(EXIT_FAILURE);
	}
	redirect_input(tools);
	redirect_output(tools);
	stat = execve(path, tools->cmd->args, environ);
	printf("%d\n", stat);
	if (stat == -1)
	{
		perror("execve");
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);
}
