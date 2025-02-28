/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:06:40 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/28 12:54:37 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

//struttura->modifichiamo tutta la funzione->tagliamo->dc

char	*expand_variables(char *line, bool global_var_enable,
		bool allow_expansion)
{
	t_exp_var	exp;

	exp.i = 0;
	exp.j = 0;
	exp.result = malloc(8192);
	if (!line || !global_var_enable || !exp.result)
		return (line ? strdup(line) : NULL);
	while (line[exp.i])
	{
		if (line[exp.i] == '$' && allow_expansion)
		{
			if (line[exp.i + 1] == '?')
			{
				exp.exit_str = ft_itoa(g_exit);
				exp.var_len = strlen(exp.exit_str);
				if (exp.j + exp.var_len < 8192)
				{
					strncpy(exp.result + exp.j, exp.exit_str, exp.var_len);
					exp.j += exp.var_len;
				}
				free(exp.exit_str);
				exp.i += 2;
			}
			else
			{
				exp.i++;
				exp.var_start = exp.i;
				while (line[exp.i] && (isalnum(line[exp.i]) || line[exp.i] == '_'))
					exp.i++;
				if (exp.var_start == exp.i)
				{
					exp.result[exp.j++] = '$';
					continue ;
				}
				exp.var_name = strndup(&line[exp.var_start], exp.i - exp.var_start);
				exp.var_value = getenv(exp.var_name);
				free(exp.var_name);
				if (exp.var_value)
				{
					exp.var_len = strlen(exp.var_value);
					if (exp.j + exp.var_len < 8192)
					{
						strncpy(exp.result + exp.j, exp.var_value, exp.var_len);
						exp.j += exp.var_len;
					}
				}
			}
		}
		else
			exp.result[exp.j++] = line[exp.i++];
	}
	exp.result[exp.j] = '\0';
	free(line);
	return (exp.result);
}
