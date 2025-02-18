/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:06:54 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/18 17:08:58 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int ft_cd(char **args, char **envp)
{
    char *path;
    envp = getenv(envp);

    if (!args[1]) // Nessun argomento: usa HOME
    {
        int i = 0;
        while (envp[i])
        {
            if (ft_strncmp(envp[i], "HOME=", 5) == 0)
            {
                path = envp[i] + 5; // Salta "HOME="
                break;
            }
            i++;
        }
        if (!envp[i]) // Se HOME non è trovata
        {
            write(2, "cd: HOME not set\n", 17);
            return 1;
        }
    }
    else
        path = args[1]; // Usa il percorso fornite
    if (chdir(path) != 0) // Cambia directory
    {
        perror("cd");
        return 1;
    }
    return 0;
}
