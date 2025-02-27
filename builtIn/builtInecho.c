/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtInecho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:35:03 by lukan             #+#    #+#             */
/*   Updated: 2025/02/27 15:42:13 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

bool	is_option_n(const char *arg)
{
	int	i;

	i = 1;
	if (arg[0] != '-' || arg[1] != 'n')
		return (false);
	i = 2;
	while (arg[i] == 'n')
		i++;
	return (arg[i] == '\0');
}

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
	len = strlen(str);
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
	bool	newline;
	int		i;
	char	*clean_arg;

	i = 1;
	newline = true;
	if (i < argc && is_option_n(argv[i]))
	{
		newline = false;
		i++;
	}
	while (i < argc)
	{
		clean_arg = argv[i];
		if (!clean_arg)
			return (fprintf(stderr, "Memory error\n"), exit(EXIT_FAILURE));
		printf("%s\n", clean_arg);
		free(clean_arg);
		i++;
		if (i < argc)
			write(1, " ", 1);
	}
	if (!newline)
		write(1, "\n", 1);
}






