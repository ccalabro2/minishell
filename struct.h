/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:38:59 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/10 15:57:05 by gd-auria         ###   ########.fr       */
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

#define MAX_LINE 1024
#define TOKEN_MAX 1024

typedef struct s_cmd		t_cmd;
typedef struct s_tokenize
t_tokenize;

typedef struct s_cmd
{
	char	*command; // nome comando
	char	**args; // argomenti
	char	*input; // file di input(se cè redirect)
	char	*output; // file di output(se cè redirect)
	int		flag; // flag per '>>' e '<<'
}	t_cmd;

typedef struct s_tokenize
{
	char	**tokens;
	char	quote;
	char	buffer [TOKEN_MAX];
	int		i;
	int		j;
	int		token_count;
	char	*input;
}	t_tokenize;

t_cmd	parse(char **tokens);
char	**tokenize(char *input);
int main();
//int		main(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char	*src);
char	**ft_split(char const *s, char c);
void	init(t_cmd *cmd);
size_t	ft_strlen(const char	*str);
void	ft_space_or_operator(t_tokenize *t, char *input);
void	ft_quote_str(t_tokenize *t, char *input);
void	ft_else_char(t_tokenize *t, char *input);
void	ft_last_token(t_tokenize *t);
void	ft_output_redirect(t_tokenize *t, char *input);
void	ft_input_redirect(t_tokenize *t, char *input);
void	ft_output_redirect_parse(t_cmd *cmd, char **tokens, int i);
void	ft_input_redirect_parse(t_cmd *cmd, char **tokens, int i);
void	trim_quotes(char *str);
void	v_read();
char	*expand_variables(char *line, bool global_var_enable);
