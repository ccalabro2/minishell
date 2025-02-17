/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:38:59 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/17 16:18:18 by gd-auria         ###   ########.fr       */
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
#include <fcntl.h>
#include <linux/limits.h>

#define MAX_LINE 1024
#define TOKEN_MAX 1024

typedef struct s_tokenize	t_tokenize;
typedef struct s_cmd		t_cmd;
typedef struct s_heredoc	t_heredoc;
typedef struct s_expander	t_expander;

typedef struct s_tokenize
{
	char	**tokens;
	char	quote;
	char	buffer [TOKEN_MAX];
	char	*input;
	int		i;
	int		j;
	int		token_count;
	int		pipe_number;
}	t_tokenize;

typedef struct s_cmd
{
	char	*command;
	char	**args;
	char	*input;
	char	*output;
	int		flag;
}	t_cmd;

typedef struct s_heredoc
{
	int		i;
	int		k;
	int		f;
	int		boll;
	char	del[250];
	char	*retun;
	char    *in_file;
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
	t_heredoc	h;
	t_cmd		*fun;
	int			pipe_number;
	bool		pipe_exist;
	char		**env;
	
} t_main;

t_cmd	parse(char **tokens);
size_t	ft_strlen(const char	*str);
//size_t	count_pipe(char **matrix);
int		main();
int		ft_pwd(void);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		heredoc(char *str, t_main *main);
int		is_all_whitespace(const char *str);
int		ft_cd(char **args, char **envp);
int		ft_export(char **args, char **envp);
int		ft_isdigit(int c);
char	**pipe_splitter(char *str, t_main *main);
// char	**tokenize(char *str, t_main *main);
void 	tokenize(char *str, t_main *main);
char	**copy_env(char **envp);
char	**remove_env_var(char **env_copy, char *var);
char	**ft_split(char const *s, char c);
char	*trim_quotes(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char	*src);
char	*expand_variables(char *line, bool global_var_enable, bool allow_expansion);
void	*ft_memset(void *ptr, int value, size_t count);
void	init(t_cmd *cmd);
void	ft_space_or_operator(t_tokenize *t, char *input);
void	ft_quote_str(t_tokenize *t, char *input);
void	ft_else_char(t_tokenize *t, char *input);
void	ft_last_token(t_tokenize *t);
void	ft_output_redirect(t_tokenize *t, char *input);
void	ft_input_redirect(t_tokenize *t, char *input);
void	ft_output_redirect_parse(t_cmd *cmd, char **tokens, int i);
void	ft_input_redirect_parse(t_cmd *cmd, char **tokens, int i);
void	v_read();
void	here_doc_open(char *del);
void	ft_echo(char **str);
void    ft_env(char **envp);
void	ft_unset(char **args, char **envp);
