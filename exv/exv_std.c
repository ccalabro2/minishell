/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exv_std.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:02:30 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/27 15:51:44 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	manage_pipe_close_utils(t_exec_manager *tools)
{
	if (tools->index == 0)
		close(tools->fd[1]);
	else if (tools->index == tools->cmd->start->pipe_number - 1)
		close(tools->old_fd[0]);
	else
	{
		close(tools->old_fd[0]);
		close(tools->fd[1]);
	}
}

void	manage_pipe_redirect_utils(t_exec_manager *tools)
{
	if (tools->index == 0)
	{
		tools->pipe_std_in = -1;
		tools->pipe_std_out = tools->fd[1];
	}
	else if (tools->index == tools->cmd->start->pipe_number - 1)
	{
		tools->pipe_std_in = tools->old_fd[0];
		tools->pipe_std_out = -1;
	}
	else
	{
		tools->pipe_std_in = tools->old_fd[0];
		tools->pipe_std_out = tools->fd[1];
	}
}

void	manage_pipe(t_exec_manager *tools)
{
	if (tools->fd[0] != -1)
	{
		tools->old_fd[0] = tools->fd[0];
		tools->old_fd[1] = tools->fd[1];
	}
	if (tools->index != (tools->cmd->start->pipe_number - 1))
	{
		if (pipe(tools->fd))
		{
			perror("Pipe creation failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		tools->fd[0] = -1;
		tools->fd[1] = -1;
	}
	manage_pipe_redirect_utils(tools);
}

void	std_exv(t_main *core)
{
	t_exec_manager	tools;
	pid_t			*pids;
	int				i;
	int				j;
	int				status;

	i = 0;
	pids = malloc(core->pipe_number * sizeof(pid_t));
	if (!core || core->pipe_number <= 0 || !core->cmdarray)
	{
		fprintf(stderr, "Invalid core structure\n");
		exit(EXIT_FAILURE);
	}
	manager_tools(&tools);
	while (i < core->pipe_number)
	{
		tools.cmd = &core->cmdarray[i];
		tools.index = i;
		if (is_builtin(core->cmdarray[i].command))
			built_in_decision_menager(&tools);
		else
		{
			manage_pipe(&tools);
			pids[i] = fork();
			if (pids[i] == -1)
			{
				perror("Fork failed");
				exit(EXIT_FAILURE);
			}
			if (pids[i] == 0)
			{
				close(tools.fd[0]);
				signal(SIGINT, SIG_DFL);
				signal(SIGTSTP, SIG_DFL);
				signal(SIGQUIT, SIG_DFL);
				exe_func(&tools);
				exit(EXIT_FAILURE);
			}
		}
		manage_pipe_close_utils(&tools);
		i++;
	}
	j = 0;
	while (j < core->pipe_number)
	{
		waitpid(pids[j], &status, 0);
		if (WIFEXITED(status))
			g_exit = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_exit = 128 + WTERMSIG(status);
		j++;
	}
	if (tools.old_fd[0] > -1)
		close(tools.old_fd[0]);
	if (tools.old_fd[1] > -1)
		close(tools.old_fd[1]);
	if (tools.fd[0] > -1)
		close(tools.fd[0]);
	if (tools.fd[1] > -1)
		close(tools.fd[1]);
	free(pids);
}
