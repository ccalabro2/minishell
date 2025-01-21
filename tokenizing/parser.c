#include "struct.h"

t_cmd *parse(char **tokens)
{
    t_cmd *cmd;
    int i;
    int arg_index;

    i = 0;
    arg_index = 0;
    init(&cmd);
    while (tokens[i])
    {
        if (strcmp(tokens[i], "<") == 0)
        {
            i++;
            if (tokens[i])
                cmd->input = strdup(tokens[i]);
        } 
        else if (strcmp(tokens[i], ">") == 0)
        {
            i++;
            if (tokens[i])
                cmd->output = strdup(tokens[i]);
        }
        else if (strcmp(tokens[i], ">>") == 0)
        {
            i++;
            if (tokens[i])
            {
                cmd->output = strdup(tokens[i]);
                cmd->flag = 1;
            }
        }
        else if (!cmd->cmd)
            cmd->cmd = strdup(tokens[i]);
        else 
        {
            cmd->args[arg_index] = strdup(tokens[i]);
            arg_index++;
        }
        i++;
    }
    cmd->args[arg_index] = NULL;
    return cmd;
}
