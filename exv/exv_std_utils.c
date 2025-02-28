/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exv_std_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:22:52 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/28 16:34:42 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	manager_tools(t_exec_manager *tools)
{
	tools->pipe_std_in = -1;
	tools->pipe_std_out = -1;
	tools->old_fd[0] = -1;
	tools->old_fd[1] = -1;
	tools->fd[0] = -1;
	tools->fd[1] = -1;
}

void	else_std_exv(t_exec_manager *tools, pid_t *pids, int *i)
{
	manage_pipe(tools);
	pids[*i] = fork();
	if (pids[*i] == -1)
	{
		printf("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (pids[*i] == 0)
	{
		close(tools->fd[0]);
		signal(SIGINT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exe_func(tools);
		exit(EXIT_FAILURE);
	}
}

void	f_while(t_exec_manager *tools, t_main *core, pid_t *pids, int *i)
{
	tools->cmd = &core->cmdarray[(*i)];
	tools->index = (*i);
	if (is_builtin(core->cmdarray[(*i)].command))
		built_in_decision_menager(tools);
	else
		else_std_exv(tools, pids, i);
	manage_pipe_close_utils(tools);
	(*i)++;
}

void	ass_close(t_exec_manager *tools)
{
	if (tools->old_fd[0] > -1)
		close(tools->old_fd[0]);
	if (tools->old_fd[1] > -1)
		close(tools->old_fd[1]);
	if (tools->fd[0] > -1)
		close(tools->fd[0]);
	if (tools->fd[1] > -1)
		close(tools->fd[1]);
}
