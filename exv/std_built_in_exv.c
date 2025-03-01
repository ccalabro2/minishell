/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_built_in_exv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:42:43 by gd-auria          #+#    #+#             */
/*   Updated: 2025/03/01 16:12:35 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

extern char	**environ;

void	call_exe_func_built_in_std(t_exec_manager *tools)
{
	int		status;
	pid_t	pid;

	manage_pipe(tools);
	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exe_func_built_in_std(tools);
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (waitpid(pid, &status, 0) == -1)
		exit(EXIT_FAILURE);
	manage_pipe_close_utils(tools);
}

void	exe_func_built_in_std(t_exec_manager *tools)
{
	char	*cmd;

	cmd = tools->cmd->command;
	if (ft_strcmp(cmd, "echo") == 0)
	{
		redirect_input(tools);
		redirect_output(tools);
		ft_echo(tools->cmd->argc, tools->cmd->args);
	}
	else if (ft_strcmp(cmd, "pwd" ) == 0)
	{
		redirect_input(tools);
		redirect_output(tools);
		ft_pwd();
	}
	else if (ft_strcmp(cmd, "env" ) == 0)
	{
		redirect_input(tools);
		redirect_output(tools);
		print_env(tools->cmd->start->env);
	}
}

void	built_in_decision_menager(t_exec_manager *tools)
{
	char	*cmd;

	cmd = tools->cmd->command;
	if (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "env") == 0)
		call_exe_func_built_in_std(tools);
	else if (ft_strcmp(cmd, "cd") == 0)
		ft_cd(tools->cmd->argc, tools->cmd->args);
	else if (ft_strcmp(cmd, "export") == 0)
	{
		if (tools->cmd->argc > 1)
			builtin_export(&tools->cmd->start->env, tools->cmd->args[1]);
		else
			printf("export: not enough arguments\n");
	}
	else if (ft_strcmp(cmd, "unset") == 0)
	{
		if (tools->cmd->argc > 1)
			builtin_unset(&tools->cmd->start->env, tools->cmd->args[1]);
		else
			printf("unset: not enough arguments\n");
	}
	else if (ft_strcmp(cmd, "exit") == 0)
		ft_exit();
	free(cmd);
}
