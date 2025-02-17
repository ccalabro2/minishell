/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:08:04 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/17 16:12:28 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char **remove_env_var(char **env_copy, char *var)
{
    int i = 0;
    int j = 0;

    // Trova la lunghezza dell'ambiente e conta gli elementi
    while (env_copy[i])
        i++;

    // Alloca nuova matrice di ambiente (con un elemento in meno)
    char **new_env = malloc(sizeof(char *) * i);
    if (!new_env)
        return NULL;

    // Copia tutte le variabili tranne quella da rimuovere
    while (env_copy[j])
    {
        if (strncmp(env_copy[j], var, strlen(var)) == 0 && env_copy[j][strlen(var)] == '=')
        {
            // Se la variabile corrisponde, non la copiamo
            j++;
            continue;
        }
        new_env[i - 1] = strdup(env_copy[j]);
        if (!new_env[i - 1])
        {
            // In caso di errore, libera la memoria e ritorna NULL
            int k = 0;
            while (k < i - 1)
            {
                free(new_env[k]);
                k++;
            }
            free(new_env);
            return NULL;
        }
        i++;
        j++;
    }
    new_env[i - 1] = NULL;  // Termina la lista con NULL
    return new_env;
}

void ft_unset(char **args, char **envp)
{
    if (!args[1])  // Se non ci sono variabili, stampa un errore
    {
        write(2, "unset: not enough arguments\n", 26);
        return 1;
    }
    // Crea una copia dell'ambiente
    char **env_copy = copy_env(envp);
    if (!env_copy)
    {
        write(2, "Error: unable to copy environment\n", 34);
        return 1;
    }
    int i = 1;
    while (args[i])
    {
        // Rimuove la variabile d'ambiente dalla copia
        env_copy = remove_env_var(env_copy, args[i]);
        if (!env_copy)
        {
            write(2, "Error: unable to remove variable\n", 32);
            return 1;
        }
        i++;
    }
    // Stampa la copia aggiornata
    int j = 0;
    while (env_copy[j])
    {
        write(1, env_copy[j], strlen(env_copy[j]));
        write(1, "\n", 1);
        j++;
    }
    // Libera la memoria della copia dell'ambiente
    int k = 0;
    while (env_copy[k])
    {
        free(env_copy[k]);
        k++;
    }
    free(env_copy);
}
