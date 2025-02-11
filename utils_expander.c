/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:06:40 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/11 14:48:51 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

/*char *expand_variables(char *line, bool global_var_enable)
{
	if ( !line || !global_var_enable)
		return strdup(line);

	char *result = malloc(4096);
	if (!result)
		return NULL;

	size_t i = 0, j = 0;
	int in_single_quotes = 0;

	while (line[i]) {
		if (line[i] == '\'') {
			in_single_quotes = !in_single_quotes;
			result[j++] = line[i++];
			continue;
		}
		if (line[i] == '$' && !in_single_quotes) {
			if (line[i + 1] == '?')
			{
				j += sprintf(result + j, "%d", 0);
				i += 2;
			}
			else if (line[i + 1] == '$')
			{
				j += sprintf(result + j, "%d", getpid());
				i += 2;
			}
			else
			{
				i++;
				size_t var_start = i;
				while (line[i] && (isalnum(line[i]) || line[i] == '_'))
					i++;

				char var_name[256];
				strncpy(var_name, &line[var_start], i - var_start);
				var_name[i - var_start] = '\0';

				char *var_value = getenv(var_name);
				if (var_value)
					j += sprintf(result + j, "%s", var_value);
			}
		} else {
			result[j++] = line[i++];
		}
	}
	result[j] = '\0';

	free(line);
	line = strdup(result);
	printf("%s\n", result);
	free(result);
	return line;
}*/
char *expand_variables(char *line, bool global_var_enable)
{
	char	*result;
	size_t	i;
	size_t	j;
	bool	in_single_quotes;
	char	var_name[256];
	char	*var_value;

	if (!line || !global_var_enable)
		return strdup(line);

	result = malloc(4096);
	if (!result)
		return NULL;

	i = 0;
	j = 0;
	in_single_quotes = false;

	while (line[i])
	{
		if (line[i] == '\'')
		{
			in_single_quotes = !in_single_quotes;
			result[j++] = line[i++];
			continue;
		}
		if (line[i] == '$' && !in_single_quotes)
		{
			if (line[i + 1] == '?')
			{
				j += sprintf(result + j, "%d", 0);
				i += 2;
			}
			else if (line[i + 1] == '$')
			{
				j += sprintf(result + j, "%d", getpid());
				i += 2;
			}
			else
			{
				i++;
				size_t var_start = i;
				while (line[i] && (isalnum(line[i]) || line[i] == '_'))
					i++;

				strncpy(var_name, &line[var_start], i - var_start);
				var_name[i - var_start] = '\0';

				var_value = getenv(var_name);
				if (var_value)
					j += sprintf(result + j, "%s", var_value);
			}
		}
		else
		{
			result[j++] = line[i++];
		}
	}

	result[j] = '\0';

	free(line);
	line = strdup(result);
	free(result);

	return line;
}

