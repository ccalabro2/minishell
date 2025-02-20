/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:38:59 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/19 17:32:29 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

typedef struct s_main
{
	char		*inputstr;
	t_heredoc	h;
	t_cmd		*cmdarray; //ovviamente contempla anche un array con 1 elemento
	int			pipe_number;
	bool		pipe_exist;
	char		**env;

}	t_main;

size_t	ft_strlen(const char	*str);
int		main(void);
int		ft_pwd(void);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		heredoc(char *str, t_main *main);
int		ft_cd(char **args, char **envp);
int		ft_export(char **args, char **envp);
int		ft_isdigit(int c);
char	**pipe_splitter(char *str, t_main *main);
char	**copy_env(char **envp);
char	**remove_env_var(char **env_copy, char *var);
char	**ft_split(char const *s, char c);
char	*trim_quotes(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char	*src);
char	*expand_variables(char *line, bool global_var_enable,
			bool allow_expansion);
void	tokenize(char *str, t_main *main);
void	*ft_memset(void *ptr, int value, size_t count);
void	*ft_calloc(size_t count, size_t size);
void	v_read(t_main *main);
void	here_doc_open(char *del);
void	ft_echo(char **str);
void	ft_env(char **envp);
void	ft_unset(char **args, char **envp);
