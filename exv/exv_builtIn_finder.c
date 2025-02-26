/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exv_builtIn_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:23:24 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/26 15:36:32 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

static char	**built_in_finder(void)
{
	char	**builtins;

	builtins = malloc(sizeof(char *) * 8);
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	return (builtins);
}

bool	is_builtin(const char *cmd)
{
	int		i;
	char	**builtins;

	i = 0;
	builtins = built_in_finder();
	while (builtins[i])
	{
		if (ft_strcmp(cmd, builtins[i]) == 0)
			return true;
		//free(builtins[i]);
		i++;
	}
	//free(builtins);
	return (false);
}
