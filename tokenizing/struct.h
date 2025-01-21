#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TOKEN_MAX 1024

typedef struct s_cmd
{
    char    *cmd; // nome comando
    char    **args; // argomenti
    char    *input; // file di input(se cè redirect)
    char    *output; // file di output(se cè redirect)
    int     flag; // flag per '>>'
}t_cmd;

void    init(t_cmd *cmd)
{
    cmd->cmd = NULL;
    cmd->args = malloc(sizeof(char *) * TOKEN_MAX);
    cmd->input = NULL;
    cmd->output = NULL;
    cmd->flag = 0;
    if (!cmd)
        return NULL;
}
