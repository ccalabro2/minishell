/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:38:59 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/29 14:45:07 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TOKEN_MAX 1024

typedef struct s_cmd	t_cmd;
typedef struct s_tokenize	t_tokenize;

typedef struct s_cmd
{
	char	*command; // nome comando
	char	**args; // argomenti
	char	*input; // file di input(se cè redirect)
	char	*output; // file di output(se cè redirect)
	int		flag; // flag per '>>'
}	t_cmd;

typedef struct s_tokenize
{
	char	**tokens;
	char	quote;
	char	buffer [TOKEN_MAX];
	int		i;
	int		j;
	int		token_count;
}	t_tokenize;


t_cmd	*parse(char **tokens);
char	**tokenize(char *input);
//int main(void);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char	*src);
char	**ft_split(char const *s, char c);
void	init(t_cmd *cmd);
size_t	ft_strlen(const char	*str);
