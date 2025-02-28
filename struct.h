/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:38:59 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/28 19:02:19 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUILTIN_H
// # define BUILTIN_H

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
#include <errno.h>
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
typedef struct s_exp_var	t_exp_var;
typedef struct s_f_path		t_f_path;
extern int					g_exit;

typedef struct s_cmd
{
	t_main	*start;
	char	*command;
	char	**args;
	char	*input;
	char	*path;
	char	*output;
	int		flag;
	int		argc;
}	t_cmd;

typedef struct s_heredoc
{
	char	del[250];
	char	*retun;
	char	*in_file;
	int		i;
	int		k;
	int		f;
	int		boll;
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

typedef struct s_exp_var
{
	size_t		i;
	size_t		j;
	size_t		var_len;
	size_t		var_start;
	char		*result;
	char		*var_name;
	char		*var_value;
	char		*exit_str;
}	t_exp_var;

typedef struct s_main
{
	t_heredoc	h;
	t_cmd		*cmdarray;
	bool		pipe_exist;
	char		*inputstr;
	char		**env;
	int			pipe_number;
	int			**pipematrix;
	int			stdin_copy;
	int			stdout_copy;

}	t_main;

typedef struct s_exec_manager
{
	t_cmd	*cmd;
	int		index;
	int		pipe_std_in;
	int		pipe_std_out;
	int		old_fd[2];
	int		fd[2];

}	t_exec_manager;

typedef struct s_f_path
{
	char	**split;
	char	*candidate;
	char	*joined;
	char	*path_env;
	int		i;

}	t_f_path;

size_t	ft_strlen(const char	*str);
bool	is_builtin(const char *cmd);
void	execute_builtin(const t_cmd *cmd);
void	std_exv(t_main *core);
void	call_exe_func(t_exec_manager *tools);
void	manager_tools(t_exec_manager *tools);
void	exe_func(t_exec_manager *tools);
void	redirect_input(t_exec_manager *tools);
void	redirect_output(t_exec_manager *tools);
void	built_in_decision_menager(t_exec_manager *tools);
void	exe_func_built_in_std(t_exec_manager *tools);
void	call_exe_func_built_in_std(t_exec_manager *tools);
void	manage_pipe_close_utils(t_exec_manager *tools);
void	manage_pipe_redirect_utils(t_exec_manager *tools);
void	manage_pipe(t_exec_manager *tools);
void	print_env(char **env);
void	builtin_export(char ***env, const char *key);
void	builtin_unset(char ***env, const char *key);
void	ft_exit(void);
void	ft_pwd(void);
void	ft_cd(int argc, char **argv);
void	ft_echo(int argc, char **argv);
void	tokenize(char *str, t_main *main);
void	*ft_memset(void *ptr, int value, size_t count);
void	*ft_calloc(size_t count, size_t size);
void	v_read(t_main *main, char **env);
void	here_doc_open(char *del);
void	handle_sigint(int signo);
void	init_signals(void);
void	handle_ctrl_d(char *line);
char	**ft_split(char const *s, char c);
char	**pipe_splitter(char *str, t_main *main);
char	**ft_op_split(char const *s, char c);
char	**ft_pipe_split(char const *s, char c);
char	**ft_split_with_quotes(const char *str);
char	**copy_env(void);
char	*find_path(t_exec_manager *tools);
char	*get_env_value(char **env, const char *key);
char	*create_env_entry(const char *key, const char *value);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_itoa(int n);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strdup(const char	*src);
char	*expand_variables(char *line, bool global_var_enable,
			bool allow_expansion);
int		free_matrix(char **matrix);
int		set_env_value(char ***env, const char *key, const char *value);
int		unset_env_value(char ***env, const char *key);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		main(void);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		heredoc(char *str, t_main *main);
int		ft_isdigit(int c);
int		new_env_value(char ***env, const char *key,
			const char *value, size_t len);
//ft_op_split.c
char	**split_words(const char *s, char **result, int word_count);
char	**free_array(char **ptr, int i);
char	*extract_operator(const char *s, int *i);
char	*extract_quotes(const char *s, int *i);
char	*extract_word(const char *s, int *i);
int		count_words(const char *str);
int		is_operator(char c);
void	count_word_check(const char *str, int *i, int *count);
void	check_parser(char ***matrix, t_cmd *elment_array, int index);
void	check_parser_two(char **matrix, t_cmd *elment_array, int *i, int *k);
void	free_main(t_main *main);
void	free_cmd(t_cmd *cmd);
void	else_std_exv(t_exec_manager *tools, pid_t *pids, int *i);
void	f_while(t_exec_manager *tools, t_main *core, pid_t *pids, int *i);
void	ass_close(t_exec_manager *tools);
void	inizialize_path(t_f_path *pather);
void	inizialize_heredoc(char *str, t_main *main);
void	bob(t_main *main);
// #endif
