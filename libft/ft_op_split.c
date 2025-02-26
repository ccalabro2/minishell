/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:14:57 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/26 18:04:33 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

int	is_operator(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

int	count_words(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i])
			break ;
		count_word_check(str, &i, &count);
	}
	return (count);
}

char	**split_words(const char *s, char **result, int word_count)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < word_count)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (!s[i])
			break ;
		if (is_operator(s[i]))
			result[k++] = extract_operator(s, &i);
		else if (s[i] == '\"')
		{
			i++;
			result[k++] = extract_quotes(s, &i);
		}
		else
			result[k++] = extract_word(s, &i);
		if (!result[k - 1])
			return (free_array(result, k - 1));
	}
	result[k] = 0;
	return (result);
}

char	**ft_op_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	(void)c;
	if (!s)
		return (0);
	word_count = count_words(s);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (0);
	return (split_words(s, result, word_count));
}
