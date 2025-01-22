#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TOKEN_MAX 1024

typedef struct s_cmd t_cmd;

typedef struct s_cmd
{
	char    *command; // nome comando
	char    **args; // argomenti
	char    *input; // file di input(se cè redirect)
	char    *output; // file di output(se cè redirect)
	int     flag; // flag per '>>'
}t_cmd;

t_cmd *parse(char **tokens);
char **tokenize(char *input);
//int main(void);
void    init(t_cmd *cmd);
