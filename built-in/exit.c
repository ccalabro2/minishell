/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:15:30 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/19 14:38:13 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int	ft_exit(char **args)
{
	int	i;
	int	exit_code;
	// Se ci sono argomenti, controlliamo se sono numerici
	if (args[1])
	{
		i = 0;
		while (args[1][i])
		{
			if (!ft_isdigit(args[1][i])) // Se un carattere non è numerico
			{
				write(2, "exit: numeric argument required\n", 32);
				return (255);// Errore di uscita
			}
			i++;
		}
		// Converte l'argomento in un numero intero
		exit_code = ft_atoi(args[1]);
		return (exit_code);// Esci con il codice fornito
	}
	// Se non ci sono argomenti, esci con codice 0
	return (0);
}
