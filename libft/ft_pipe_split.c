/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:05:34 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/27 11:34:27 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

static int	pipe_count_words(const char *str)
{
	int	i;
	int	count;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '\0' && str[i] != '"')
				i++;
			if (str[i] == '"')
				i++;
			else
				return (0);
		}
		else if (str[i] == '|')
		{
			i++;
			count++;
		}
		else
			i++;
	}
	return (count + 1);
}


static char	**pipe_split_words(const char *s, char **result, int pipe_count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < pipe_count)
	{
		j = 0;
		while (s[i])
		{
			if (s[i] == '\"')
			{
				i++;
				j++;
				while (s[i] != '\0' && s[i] != '\"')
				{
					i++;
					j++;
				}
			}
			if (s[i] == '|')
			{
				i++;
				j++;
				break ;
			}
			i++;
			j++;
		}
		if (s[i] == '\0')
		{
			i++;
			j++;
		}
		result[k] = strndup(s +(i - j), j - 1);
		k++;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_pipe_split(char const *s, char c)
{
	char	**result;
	char	**tmp_matrix;
	int		word_count;
	int		l;

	(void)c;
	if (!s)
		return (0);
	word_count = pipe_count_words(s);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (0);
	tmp_matrix = pipe_split_words(s, result, word_count);
	l = 0;
	while (result[l])
		l++;
	return (tmp_matrix);
}
