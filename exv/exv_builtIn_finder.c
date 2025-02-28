/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exv_builtIn_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:23:24 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/28 11:52:19 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

bool	is_builtin(const char *cmd)
{
	if (!cmd || !*cmd)
		return (false);
	if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	if (ft_strcmp(cmd, "export") == 0)
		return (true);
	if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	if (ft_strcmp(cmd, "env") == 0)
		return (true);
	if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	return (false);
}
