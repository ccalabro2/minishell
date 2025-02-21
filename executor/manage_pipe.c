/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:51:50 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/21 17:26:22 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**/
/*read stdin from the pipe*/
// void	piperead(int **pipematrix, int i)
// {
// 	close(pipematrix[i - 1][WRITE_END]);
// 	dup2(pipematrix[i - 1][READ_END], STDIN_FILENO);
// 	close(pipematrix[i - 1][READ_END]);
// }

// /*write stdout in the pipe*/
// void	pipewrite(int **pipematrix, int i)
// {
// 	close(pipematrix[i][READ_END]);
// 	dup2(pipematrix[i][WRITE_END], STDOUT_FILENO);
// 	close(pipematrix[i][WRITE_END]);
// }

// /*close all pipe*/
// void	pipeclose(int **pipematrix, int cmdlist_len)
// {
// 	int	n;

// 	n = -1;
// 	while (++n < (cmdlist_len - 1))
// 	{
// 		close(pipematrix[n][READ_END]);
// 		close(pipematrix[n][WRITE_END]);
// 	}
// }

// /*Execute builtins or external command*/
// void	ft_execve(t_cmd *element_array, char **env)
// {
// 	//char	**envlist;
// 	// if (builtinex(tmp_cmdlist, &genvlist) == 1)//AAAAAAa questa riga DEVE ESSERE DECOMMENTATA  E GESTITA SUCCESSIVAMEMTE
// 	// 	return ;
// 	//tmp_cmdlist->path = get_cmdpath(tmp_cmdlist->cmd);
// 	//envlist = litoma(genvlist);
// 	execve(element_array->path, element_array->args, env);
// }

// /* Handle child process execution */
// void	handle_child_process(t_cmd *cmdarray, int pipe_number, int **pipematrix,
// 		char **env, t_cmd *element_array, int i, int saved_stdout)
// {
// 	//int		ret;
// 	//int		is_builtin;
// 	//t_env	**env;
// 	//is_builtin = 0;

// 	(void)saved_stdout; //aaa quando sblocchi le redirectio questo lo cancelli
// 	if (i > 0)
// 		piperead(pipematrix, i);
// 	if (cmdarray + i) //TODO vedere se e'corretta la i oppure e'da passare un altra variabbiiele
// 		pipewrite(pipematrix, i);
// 	//if (check_builtin(tmp_cmdlist) == 1) //AAAAAAa questa riga DEVE ESSERE DECOMMENTATA  E GESTITA SUCCESSIVAMEMTE
// 	//	is_builtin = 1;
// 	//ret = ihoa_redirops(tmp_cmdlist->redirlist, saved_stdout, is_builtin); ///aaa non hai una lista di redirecton
// 	//if (ret == 0)
// 	//	exit(1);
// 	pipeclose(pipematrix, pipe_number);
// 	//env = data->env;
// 	ft_execve(element_array, env);
// 	exit(1);
// }

// /* Fork along the pipes aaa...vedi i paramentri di data */
// void	pipefork(t_cmd *cmdarray, int pipe_number, int **pipematrix, char **env,
// 		t_cmd *element_array, int i)
// {
// 	int		pid;
// 	int		saved_stdout;
// 	//t_cmd	tmp_cmdarray;

// 	//tmp_cmdarray = element_array;
// 	pid = fork();
// 	saved_stdout = dup(STDOUT_FILENO);
// 	if (pid == 0)
// 		handle_child_process(cmdarray, pipe_number, pipematrix, env,
// 			element_array, i, saved_stdout);
// }

// //aaa aggiungere il controllo sul lunghezza
// int	check_cmdpath(t_cmd *cmdarray)
// {
// 	while (cmdarray)
// 	{
// 		if (!cmdarray->path)
// 			return (0);
// 		cmdarray++;
// 	}
// 	return (1);
// }
// /*
// typedef struct s_pipex_data
// {
// 	t_cmd	*cmdlist; cmdarray

// 	int		cmdlist_len; pipe_numnber
// 	int		**pipematrix; _la tua matrice di pipe //in executor
// 	t_env	**env; // env

// }	t_pipex_data;*/
// /*execute pipes
// stats all forks in a while, then the father waits.
// Quanto arrivo qui e'perche'ho la certezza che ci sia almeno una pipe.
// */

// int	pipex(t_cmd *cmdarray, int pipe_number, int **pipematrix, char **env)
// {
// 	int		i;
// 	int		j;
// 	int		status;
// 	//t_cmd	*tmp_cmdlist;
// 	j = 0;

// 	if (!cmdarray)
// 		return (0);
// 	else
// 	{
// 		printf("ecco il comando:%s.\n", cmdarray[0].command);
// 		printf("ecco il comando:%s.\n", cmdarray[1].command);
// 	}
// 	i = -1; //AAA vlurtare iil percorso e inseriee eventualmente j , k ecc...
// 	while (++i < pipe_number) //aaa verificare lunghezza array
// 	{
// 		if (i > 0)
// 			j++;
// 		pipefork(cmdarray, pipe_number, pipematrix, env, &cmdarray[j], i);
// 	}
// 	pipeclose(pipematrix, pipe_number);
// 	i = 0;
// 	while (i < pipe_number)
// 	{
// 		wait(&status);
// 		g_exit = WEXITSTATUS(status);
// 		i++;
// 	}
// 	return (0);
// }

#include "../struct.h"

void	init_pipe(t_exec *exec)
{
	exec->pipe_stdin = -1;
	exec->pipe_stdout = -1;
	exec->old_fd[0] = -1;
	exec->old_fd[1] = -1;
	exec->curr_fd[0] = -1;
	exec->curr_fd[1] = -1;
}

void	manage_pipe_close_utils(t_exec *exec)
{
		if (exec->i == 0)
			close(exec->curr_fd[1]);
		else if (exec->i == exec->cmd->start->pipe_number - 1)
			close(exec->old_fd[0]);
		else
		{
			close(exec->old_fd[0]);
			close(exec->curr_fd[1]);
		}
}
void	manage_pipe_redirect_utils(t_exec *exec)
{
	if (exec->i == 0)
	{
		exec->pipe_stdin = -1;
		exec->pipe_stdout = exec->curr_fd[1];
	}
	else if (exec->i == exec->cmd->start->pipe_number - 1)
	{
		exec->pipe_stdin = exec->old_fd[0];
		exec->pipe_stdout = -1;
	}
	else
	{
		exec->pipe_stdin = exec->old_fd[0];
		exec->pipe_stdout = exec->curr_fd[1];
	}
}
void manage_pipe(t_exec *exec)
{
	if(exec->curr_fd[0] != -1)
	{
		exec->old_fd[0] = exec->curr_fd[0];
		exec->old_fd[1] = exec->curr_fd[1];
	}
	if (exec->i != (exec->cmd->start->pipe_number - 1))
	{
		if (pipe(exec->curr_fd))
		{
			perror("Pipe creation failed");
			exit(EXIT_FAILURE);
		}
	}
	manage_pipe_redirect_utils(exec);
}


void std_exv(t_main *main)
{
    t_exec   exec;
    int           i;
    pid_t           *pids;
    int             status;
	int			j;

    i = 0;
	pids = malloc(sizeof(pid_t) * main->pipe_number);
    if (!main || main->pipe_number <= 0 || !main->cmdarray)
    {
        fprintf(stderr, "Invalid main structure\n");
        exit(EXIT_FAILURE);
    }
    init_pipe(&exec);
    while (i < main->pipe_number)
    {
        exec.cmd = &main->cmdarray[i];
        exec.i = i;
        // if (is_builtin(main->cmdarray[i].command))
        //     built_in_decision_menager(&exec);
        // else
        //{
            manage_pipe(&exec);
            pids[i] = fork();
            if (pids[i] == -1)
            {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            }
            if (pids[i] == 0) // Processo figlio
            {
                signal(SIGINT, SIG_DFL);
                signal(SIGTSTP, SIG_DFL);
                signal(SIGQUIT, SIG_DFL);
                //exe_func(&exec);
                exit(EXIT_FAILURE);
            }
    	}
        manage_pipe_close_utils(&exec);
        i++;
    //}
    j = 0;
	while (j < main->pipe_number)
	{
		waitpid(pids[j], &status, 0);
		if (WIFEXITED(status))
			g_exit = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_exit = 128 + WTERMSIG(status);
		j++;
	}
    close(exec.old_fd[0]);
    close(exec.old_fd[1]);
    close(exec.curr_fd[0]);
    close(exec.curr_fd[1]);
}
