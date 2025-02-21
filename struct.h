/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:38:59 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/21 21:51:20 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <linux/limits.h>

#define MAX_LINE 1024
#define TOKEN_MAX 1024

#define PIPE_IN "PIPE_IN"
#define PIPE_OUT "PIPE_OUT"

#define READ_END 0
#define WRITE_END 1

typedef struct s_tokenize	t_tokenize;
typedef struct s_cmd		t_cmd;
typedef struct s_heredoc	t_heredoc;
typedef struct s_expander	t_expander;
typedef struct s_main		t_main;
extern int					g_exit;

// typedef struct s_tokenize
// {
// 	char	**tokens;
// 	char	quote;
// 	char	buffer [TOKEN_MAX];
// 	char	*input;
// 	int		i;
// 	int		j;
// 	int		token_count;
// 	int		pipe_number;
// }	t_tokenize;

typedef struct s_cmd
{
	char	*command;
	char	**args;
	char	*input;
	char	*path;
	char	*output;
	int		flag;
	t_main	*start;
}	t_cmd;

typedef struct s_heredoc
{
	int		i;
	int		k;
	int		f;
	int		boll;
	char	del[250];
	char	*retun;
	char	*in_file;
}	t_heredoc;

typedef struct s_expander
{
	size_t	i;
	size_t	j;
	size_t	var_len;
	char	*result;
	char	*var_name;
	char	*var_value;
}	t_expander;

// typedef struct s_exec ---- COMMENTATO MOMENT. PERCHE USIAMO QUELLA DI FEDERICO... MODIFICHEREMO QUESTO
// {
// 	t_cmd	*cmd;
// 	int			i;
// 	int		pipe_stdin;
// 	int		pipe_stdout;
// 	int		curr_fd[2];
// 	int		old_fd[2];
// }	t_exec;

typedef struct s_main
{
	char		*inputstr;
	t_heredoc	h;
	t_cmd		*cmdarray; //ovviamente contempla anche un array con 1 elemento
	int			pipe_number;
	bool		pipe_exist;
	int			**pipematrix;
	char		**env;
	int             stdin_copy;
    int             stdout_copy;

}	t_main;

typedef struct s_exec_manager
{
	t_cmd	*cmd;
	int		index;
	int			pipe_std_in;
	int			pipe_std_out;
	int 		old_fd[2];
	int			fd[2];

} t_exec_manager;

void	execute_builtin(const t_cmd *cmd);
bool	is_builtin(const char *cmd);
void	std_exv(t_main *core);
void 	call_exe_func(t_exec_manager *tools);
void    manager_tools(t_exec_manager *tools);
void	exe_func(t_exec_manager *tools);
char 	*find_path(t_exec_manager *tools);
void	redirect_input(t_exec_manager *tools);
void 	redirect_output(t_exec_manager *tools);
void 	built_in_decision_menager(t_exec_manager *tools);
void 	exe_func_built_in_std(t_exec_manager *tools);
void	call_exe_func_built_in_std(t_exec_manager *tools);
void	manage_pipe_close_utils(t_exec_manager *tools);
void	manage_pipe_redirect_utils(t_exec_manager *tools);
void	manage_pipe(t_exec_manager *tools);
int		free_matrix(char **matrix);

// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//

#ifndef BUILT_IN_H
#define BUILT_IN_H



void    print_env(char **env);
void    builtin_export(char ***env, const char *key, const char *value);
void    builtin_unset(char ***env, const char *key);
void    ft_exit();
void    ft_pwd();
void 	ft_cd(t_cmd *cmd);
void	ft_echo(char **argv);


#endif

size_t	ft_strlen(const char	*str);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		main(void);
//int		ft_pwd(void);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		heredoc(char *str, t_main *main);
//int		ft_cd(char **args, char **envp);
//int		ft_export(char **args, char **envp);
int		ft_isdigit(int c);
char **ft_split(const char *s, char c);
char	**pipe_splitter(char *str, t_main *main);
//char	**copy_env(char **envp);
//char	**remove_env_var(char **env_copy, char *var);
char	**ft_op_split(char const *s, char c);
char	**ft_pipe_split(char const *s, char c);
//char	*trim_quotes(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char	*src);
char	*expand_variables(char *line, bool global_var_enable,
			bool allow_expansion);
void	tokenize(char *str, t_main *main);
void	*ft_memset(void *ptr, int value, size_t count);
void	*ft_calloc(size_t count, size_t size);
void	v_read(t_main *main);
void	here_doc_open(char *del);
//void	ft_echo(char **str);
//void	ft_env(char **envp);
//void	ft_unset(char **args, char **envp);
void	handle_sigint(int signo);
void	init_signals(void);
void	handle_ctrl_d(char *line);
//int		pipex(t_cmd *cmdarray, int pipe_number, int **pipematrix, char **env);
//void	ft_execve(t_cmd *element_array, char **env);
//void	generate_pipematrix(int number_pipe, t_main *main);
// void	std_exv(t_main *main);
// void	manage_pipe(t_exec *exec);
// void	manage_pipe_redirect_utils(t_exec *exec);
// void	manage_pipe_close_utils(t_exec *exec);
// void	init_pipe(t_exec *exec);
