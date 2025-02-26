/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:06:40 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/26 16:33:57 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char	*expand_variables(char *line, bool global_var_enable,
		bool allow_expansion)
{
	size_t		i;
	size_t		j;
	size_t		var_len;
	size_t		var_start;
	char		*result;
	char		*var_name;
	char		*var_value;
	char		*exit_str;

	i = 0;
	j = 0;
	result = malloc(8192);
	if (!line || !global_var_enable || !result)
		return (line ? strdup(line) : NULL);
	while (line[i])
	{
		if (line[i] == '$' && allow_expansion)
		{
			if (line[i + 1] == '?')
			{
				exit_str = ft_itoa(g_exit);
				var_len = strlen(exit_str);
				if (j + var_len < 8192)
				{
					strncpy(result + j, exit_str, var_len);
					j += var_len;
				}
				free(exit_str);
				i += 2;
			}
			else
			{
				i++;
				var_start = i;
				while (line[i] && (isalnum(line[i]) || line[i] == '_'))
					i++;
				if (var_start == i)
				{
					result[j++] = '$';
					continue ;
				}
				var_name = strndup(&line[var_start], i - var_start);
				var_value = getenv(var_name);
				free(var_name);
				if (var_value)
				{
					var_len = strlen(var_value);
					if (j + var_len < 8192)
					{
						strncpy(result + j, var_value, var_len);
						j += var_len;
					}
				}
			}
		}
		else
			result[j++] = line[i++];
	}
	result[j] = '\0';
	free(line);
	return (strdup(result));
}
