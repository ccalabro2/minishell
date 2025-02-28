/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:40:53 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/28 19:25:57 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	inizialize_heredoc(char *str, t_main *main)
{
	main->h.f = 0;
	main->h.k = 0;
	main->h.i = 0;
	main->h.boll = 1;
	main->h.retun = str;
	ft_memset(main->h.del, 0, 250);
}

void	bob(t_main *main)
{
	main->h.retun[main->h.f] = '\0';
	if (main->h.boll == 0)
		here_doc_open(main->h.del);
}

void	last_fun(t_main *main)
{
	tokenize(main->inputstr, main);
	std_exv(main);
	if (main->inputstr)
		add_history(main->inputstr);
	unlink("IN_HEREDOC");
}

void	prompt(t_main *main, char **env)
{
	main->env = env;
	init_signals();
	main->inputstr = readline("Minishell > ");
}

void	shortp(t_main *main)
{
	handle_ctrl_d(main->inputstr);
	heredoc(main->inputstr, main);
}
