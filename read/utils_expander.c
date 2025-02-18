/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:06:40 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/18 17:12:54 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char	*expand_variables(char *line, bool global_var_enable, bool allow_expansion)
{
	size_t	i;
	size_t	j;
	size_t	var_len;
	char	*result;
	char	*var_name;
	char	*var_value;

	if (!line || !global_var_enable)
		return strdup(line);

	result = malloc(8192);
	if (!result)
		return NULL;

	i = 0;
	j = 0;

	while (line[i])
	{
		if (line[i] == '$' && allow_expansion)
		{
			if (line[i + 1] == '?')
			{
				// Aggiungere un intero alla stringa
				const char *pid_str = "0"; // Simuliamo il valore di $? come 0
				size_t len = strlen(pid_str);
				if (j + len < 8192)
				{
					strncpy(result + j, pid_str, len);
					j += len;
				}
				i += 2;
			}
			else if (line[i + 1] == '$')
			{
				const char *pid_str = "1234"; // Simuliamo il pid
				size_t len = strlen(pid_str);
				if (j + len < 8192)
				{
					strncpy(result + j, pid_str, len);
					j += len;
				}
				i += 2;
			}
			else
			{
				i++;
				size_t var_start = i;

				while (line[i] && (isalnum(line[i]) || line[i] == '_'))
					i++;

				if (var_start == i)
				{
					result[j++] = '$';
					continue;
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
		{
			result[j++] = line[i++];
		}
	}
	result[j] = '\0';

	free(line);
	return strdup(result);
}

//funzione senza hardcoded ma con	UN PORCODIO DI FOR ALLA FINE
/*extern int g_exit_code;  // Questa variabile dovrebbe essere definita globalmente, esempio: int g_exit_code = 0;

char *expand_variables(char *line, bool global_var_enable, bool allow_expansion)
{
	if (!line || !global_var_enable)
		return strdup(line);

	char *result = malloc(8192);
	if (!result)
		return NULL;

	size_t i = 0, j = 0;

	while (line[i])
	{
		if (line[i] == '$' && allow_expansion)
		{
			if (line[i + 1] == '?')
			{
				// Espandere $?, che è il codice di uscita dell'ultimo comando
				char exit_code_str[32];
				int len = 0;

				// Convertire il codice di uscita in stringa
				if (g_exit_code == 0)
				{
					exit_code_str[len++] = '0';
				}
				else
				{
					int tmp = g_exit_code;
					while (tmp > 0)
					{
						exit_code_str[len++] = (tmp % 10) + '0';
						tmp /= 10;
					}
					// Invertire la stringa
					for (int start = 0, end = len - 1; start < end; start++, end--)
					{
						char temp = exit_code_str[start];
						exit_code_str[start] = exit_code_str[end];
						exit_code_str[end] = temp;
					}
				}
				exit_code_str[len] = '\0';

				int k = 0;
				while (exit_code_str[k])
				{
					result[j++] = exit_code_str[k++];
				}
				i += 2;
			}
			else if (line[i + 1] == '$')
			{
				// Espandere $$, che è il PID del processo corrente
				char pid_str[32];
				int len = 0;

				// Convertire il PID in stringa
				int pid = getpid();
				while (pid > 0)
				{
					pid_str[len++] = (pid % 10) + '0';
					pid /= 10;
				}
				// Invertire la stringa
				for (int start = 0, end = len - 1; start < end; start++, end--)
				{
					char temp = pid_str[start];
					pid_str[start] = pid_str[end];
					pid_str[end] = temp;
				}
				pid_str[len] = '\0';

				int k = 0;
				while (pid_str[k])
				{
					result[j++] = pid_str[k++];
				}
				i += 2;
			}
			else
			{
				// Espansione di altre variabili di ambiente (es: $USER, $HOME)
				i++;
				size_t var_start = i;

				while (line[i] && (isalnum(line[i]) || line[i] == '_'))
					i++;

				if (var_start == i)
				{
					result[j++] = '$';  // Non è una variabile valida, copia il simbolo $
					continue;
				}

				char *var_name = strndup(&line[var_start], i - var_start);
				char *var_value = getenv(var_name);  // Ottieni il valore della variabile di ambiente

				free(var_name);

				if (var_value)
				{
					int var_len = 0;
					while (var_value[var_len])
						var_len++;

					if (j + var_len < 8192)
					{
						for (int k = 0; k < var_len; k++)
						{
							result[j++] = var_value[k];
						}
					}
				}
			}
		}
		else
		{
			result[j++] = line[i++];
		}
	}
	result[j] = '\0';

	free(line);
	return strdup(result);
}*/
