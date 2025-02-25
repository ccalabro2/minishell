/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtInEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:51:55 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/25 12:49:21 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

// int set_env_value(char **env, const char *key, const char *value);
// int unset_env_value(char **env, const char *key);

void print_env(char **env)
{
    size_t  i;

    i = 0;
    while (env[i])
        printf("%s\n", env[i++]);
    exit(0);
}

void builtin_export(char ***env, const char *key)
{
    char **split_prompt;

    split_prompt = ft_split(key, '=');
    printf("{%s} , {%s}\n", split_prompt[0], split_prompt[1]);
    if (set_env_value(env, split_prompt[0], split_prompt[1]) == -1)
    {
        perror("export: failed to set \n");
    }
}

void builtin_unset(char ***env, const char *key)
{
    if (!key)
    {
        fprintf(stderr, "unset: missing argument\n");
        return;
    }
    if (unset_env_value(env, key) == -1)
    {
        fprintf(stderr, "unset: `%s` not found\n", key);
    }
}

