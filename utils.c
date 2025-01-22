#include "struct.h"

void    init(t_cmd *cmd)
{
	cmd->command = NULL;
	cmd->args = malloc(sizeof(char *) * TOKEN_MAX);
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->flag = 0;
	if (!cmd)
		return ;
}
