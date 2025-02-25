/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exv_builtIn_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:23:24 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/24 15:44:39 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../struct.h"

static char **built_in_finder()
{
    char **builtins = malloc(sizeof(char *) * 8);
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

void execute_builtin(const t_cmd *cmd)
{
    if (ft_strcmp(cmd->command, "echo") == 0)
        ft_echo(cmd->argc, cmd->args);
    else if (ft_strcmp(cmd->command, "cd") == 0)
        ft_cd(cmd->argc, cmd->args);
    else if (ft_strcmp(cmd->command, "pwd") == 0)
        ft_pwd();
    else if (ft_strcmp(cmd->command, "export") == 0)
        printf("export");
    else if (ft_strcmp(cmd->command, "unset") == 0)
        printf("unset");
    else if (ft_strcmp(cmd->command, "env") == 0) 
        print_env(cmd->start->env);
    else if (ft_strcmp(cmd->command, "exit") == 0) 
        ft_exit();
}

bool is_builtin(const char *cmd)
{
    int i;
    char **builtins;

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
    return false;
}
