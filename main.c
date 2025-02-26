/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:33:52 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/26 20:02:48 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	g_exit = 0;

void	std_directory_save(t_main *core)
{
	core->stdin_copy = dup(STDIN_FILENO);
	if (core->stdin_copy == -1)
	{
		perror("dup stdin");
		exit(EXIT_FAILURE);
	}
	core->stdout_copy = dup(STDOUT_FILENO);
	if (core->stdout_copy == -1)
	{
		perror("dup stdout");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	t_main	main;

	v_read(&main, copy_env());
}
