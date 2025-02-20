/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:26:44 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/20 16:36:36 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	handle_sigint(int signal)
{
	(void)signal;
	write(1, "\n", 1);            // Va a capo
	rl_replace_line("", 0);       // Cancella la linea corrente
	rl_on_new_line();             // Posiziona il cursore sul nuovo prompt
	rl_redisplay();               // Ridisegna il prompt
}

void	init_signals(void)
{
	signal(SIGINT, handle_sigint); // Gestisce Ctrl+C
	signal(SIGQUIT, SIG_IGN);      // Ignora Ctrl+'\'
}

void	handle_ctrl_d(char *line)
{
	if (!line) // readline ritorna NULL se viene premuto Ctrl+D
	{
		write(1, "exit\n", 5);  // Stampa "exit"
		exit(0);                // Termina la shell con status 0
	}
}
