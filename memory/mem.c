#include <stdlib.h>
#include "../struct.h"

void	free_args(char **args)
{
	int i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	free_heredoc(t_heredoc *h)
{
	if (h)
	{
		if (h->retun)
			free(h->retun);
		if (h->in_file)
			free(h->in_file);
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		free_args(cmd->args);
		if (cmd->input)
			free(cmd->input);
		if (cmd->path)
			free(cmd->path);
		if (cmd->output)
			free(cmd->output);
		free(cmd);
	}
}
