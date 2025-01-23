#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TOKEN_MAX 1024

typedef struct s_cmd t_cmd;

typedef struct s_cmd
{
	char	*command; // nome comando
	char	**args; // argomenti
	char	*input; // file di input(se cè redirect)
	char	*output; // file di output(se cè redirect)
	int	flag; // flag per '>>'
}t_cmd;

t_cmd *parse(char **tokens);
char **tokenize(char *input);
//int main(void);
int my_strcmp(const char *str1, const char *str2);
int	ft_atoi(const char *str);
char	*ft_strdup(const char	*src);
char	**ft_split(char const *s, char c);
void	init(t_cmd *cmd);
size_t	ft_strlen(const char	*str);
