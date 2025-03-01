/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtInecho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:35:03 by lukan             #+#    #+#             */
/*   Updated: 2025/03/01 16:01:21 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char	*remove_quotes(const char *str)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = 0;
	j = 0;
	result = malloc(len + 1);
	len = ft_strlen(str);
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

void	ft_echo(int argc, char **argv)
{
	int		i;
	char	*clean_arg;

	i = 1;
	while (i < argc)
	{
		clean_arg = argv[i];
		if (!clean_arg)
			return (printf("Memory error\n"), exit(EXIT_FAILURE));
		if (argv[1][0] == '-' && argv[1][1] == 'n')
		{
			i++;
			printf("%s", argv[i]);
		}
		else
			printf("%s\n", clean_arg);
		free(clean_arg);
		i++;
	}
}
