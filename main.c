#include "struct.h"

int main()
{
    t_cmd *cmd;
    char input[] = "echo 'Hello World' > file.txt";
    char **tokens = tokenize(input);
    int i;

    i = 0;
    while (tokens[i])
    {
        printf("Token[%d]: %s\n", i, tokens[i]);
        i++;
    }

    cmd = parse(tokens);
    printf("\nCommand: %s\n", cmd->cmd);
    i = 0;
    while (cmd->args[i]) {
        printf("Arg[%d]: %s\n", i, cmd->args[i]);
        i++;
    }
    if (cmd->input)
        printf("Input: %s\n", cmd->input);
    if (cmd->output)
        printf("Output: %s (flag: %d)\n", cmd->output, cmd->flag);

    // Libera la memoria
    i = 0;
    while (tokens[i]) {
        free(tokens[i]);
        i++;
    }
    free(tokens);

    free(cmd->cmd);
    i = 0;
    while (cmd->args[i]) {
        free(cmd->args[i]);
        i++;
    }
    free(cmd->args);
    free(cmd->input);
    free(cmd->output);
    free(cmd);

    return 0;
}
