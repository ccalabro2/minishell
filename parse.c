/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:36:40 by ccalabro          #+#    #+#             */
/*   Updated: 2025/01/29 21:09:02 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TODO:
-gestire anche le pipe
-accorciare la funzione dividendola in: (es)ft_operator per i primi 3 if e ft_cdm_args
-fare per l'operatore < quello che ho fatto per il maggiore............fatto*/
#include "struct.h"

t_cmd	parse(char **tokens)
{
	t_cmd	cmd;
	int		i;
	int		arg_index;

	i = 0;
	arg_index = 0;
	init(&cmd);
	while (tokens[i])
	{
		printf("TOKEN %s\n", tokens[i]);
//per operatori << e <
		if (*tokens[i] == '<')
		{
			if (*(tokens[i] + 1))
			{
				//printf("TOKEN %s\n", tokens[i]);
				if (tokens[i])
				{
					cmd.input = strdup(tokens[i]);
					cmd.flag = 1;
				}
			}
			else
			{
				//printf("TOKEN %s\n", tokens[i]);
				if (tokens[i])
					cmd.input = strdup(tokens[i]);
			}
		}
//per operatori >> e >
		else if (*tokens[i] == '>')
		{
			if (*(tokens[i] + 1)) //scrivo cosi perche con il tokenize l'ho divisi in modo che per certo il carattere successivo sará null oppure sará >
			{
				//printf("TOKEN %s\n", tokens[i]);
				if (tokens[i])
				{
					cmd.output = strdup(tokens[i]);
					cmd.flag = 1;
				}
			}
			else
			{
				//printf("TOKEN %s\n", tokens[i]);
				if (tokens[i])
					cmd.output = strdup(tokens[i]);
			}
		}
		else if (!cmd.command)
		{
			//printf("TOKEN %s\n", tokens[i]);
			cmd.command = strdup(tokens[i]);
		}
		else
		{
			//printf("TOKEN %s\n", tokens[i]);
			cmd.args[arg_index] = strdup(tokens[i]);
			arg_index++;
		}
		i++;
	}
	cmd.args[arg_index] = NULL;
	return (cmd);
}
