/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:19 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/19 14:50:55 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	// Stampa tutte le variabili d'ambiente
	while (envp[i])
	{
		write(1, envp[i], strlen(envp[i]));
		write(1, "\n", 1);
		i++;
	}
}

char	**copy_env(char **envp)
{
	int		i;
	int		j;
	int		k;
	char	**env_copy;

	i = 0;
	while (envp[i])
		i++;
	// Alloca una matrice di stringhe per la copia
	env_copy = malloc(sizeof(char *) * (i + 1));
	if (!env_copy)
		return (NULL);
	// Copia ogni variabile d'ambiente
	j = 0;
	while (j < i)
	{
		env_copy[j] = strdup(envp[j]);
		if (!env_copy[j])
		{
			// In caso di errore, libera la memoria e ritorna NULL
			k = 0;
			while (k < j)
			{
				free(env_copy[k]);
				k++;
			}
			free(env_copy);
			return (NULL);
		}
		j++;
	}
	env_copy[i] = NULL; // Termina la lista con NULL
	return (env_copy);
}

int	ft_export(char **args, char **envp)
{
	char	**env_copy;
	char	*arg;
	char	*equal_sign;
	int		i;
	int		j;
	int		k;

	env_copy = copy_env(envp);
	if (!env_copy)
	{
		write(2, "Error: unable to copy environment\n", 34);
		return (1);
	}
	if (!args[1]) // Se non ci sono argomenti, stampa le variabili d'ambiente
	{
		i = 0;
		while (env_copy[i])
		{
			write(1, env_copy[i], ft_strlen(env_copy[i]));
			write(1, "\n", 1);
			i++;
		}
		// Libera la memoria della copia
		j = 0;
		while (env_copy[j])
		{
			free(env_copy[j]);
			j++;
		}
		free(env_copy);
		return (0);
	}
	// Processa ogni variabile di ambiente passata come argomento
	i = 1; //non so se era un'altra variabile ho l'abbiamo solo riassegnata
	while (args[i])
	{
		arg = args[i];
		equal_sign = ft_strchr(arg, '=');

		if (equal_sign)
		{
			*equal_sign = '\0';// Rimuovi "="
			// Modifica la copia dell'ambiente
			setenv(arg, equal_sign + 1, 1);
		}
		else
		{
			// Se non c'è "=", esporta la variabile se esiste
			if (getenv(arg))
				setenv(arg, getenv(arg), 1);
			else
				write(2, "export: not a valid identifier\n", 30);
		}
		i++;
	}
	// Libera la memoria della copia
	k = 0;
	while (env_copy[k])
	{
		free(env_copy[k]);
		k++;
	}
	free(env_copy);
	return (0);
}
