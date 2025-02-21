/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exv_builtIn_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:23:24 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/21 21:50:42 by gd-auria         ###   ########.fr       */
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
    if (strcmp(cmd->command, "echo") == 0) {
        ft_echo(cmd->args);
    } else if (strcmp(cmd->command, "cd") == 0) {
         printf("cd \n");
    } else if (strcmp(cmd->command, "pwd") == 0) {
        ft_pwd();
    } else if (strcmp(cmd->command, "export") == 0) {
        printf("export");
    } else if (strcmp(cmd->command, "unset") == 0) {
        printf("unset");
    } else if (strcmp(cmd->command, "env") == 0) {
        print_env(cmd->start->env);
    } else if (strcmp(cmd->command, "exit") == 0) {
        ft_exit();
    }
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
