/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtInEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:51:55 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/21 20:08:36 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int set_env_value(char **env, const char *key, const char *value);
int unset_env_value(char **env, const char *key);

void print_env(char **env)
{
    size_t  i;

    i = 0;
    while (env[i])
        printf("%s\n", env[i++]);
    exit(0);
}

void builtin_export(char ***env, const char *key, const char *value)
{
    if (set_env_value(*env, key, value) == -1)
    {
        perror("export: failed to set \n");
    }
}

void builtin_unset(char ***env, const char *key)
{
    if (unset_env_value(*env, key) == -1)
    {
        perror("unset:  not found\n");
    }
}
