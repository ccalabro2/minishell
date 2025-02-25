/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:05:34 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/25 17:34:17 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"
static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	is_operator(char c)
{
	return (c == '<' || c == '>' || c == '|');//AAA
}

static int	count_words(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i])
			break;
		if (is_operator(str[i]))
		{
			count++;
			if ((str[i] == '<' || str[i] == '>') && str[i + 1] == str[i])
				i++;
			i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\0' && str[i] != '\"')
				i++;
			if (str[i] == '\"')
			{
				i++;
				count++;
			}
		}
		else
		{
			count++;
			while (str[i] && !is_operator(str[i]) && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	//printf("qui ho finito\n");
	return (count);
}

static char	*extract_word(const char *s, int *i)
{
	int start;

	start = *i;
	while (s[*i] && !is_operator(s[*i]) && s[*i] != ' ' && s[*i] != '\t')
	{
		(*i)++;
	}
	return (strndup(&s[start], *i - start));
}

static char	*extract_quotes(const char *s, int *i)
{
	int start;

	start = *i;
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		(*i)++;
	}
	return (strndup(&s[start], *i - start));
}



static char	*extract_operator(const char *s, int *i)
{
	char *op;

	if ((s[*i] == '<' || s[*i] == '>') && s[*i + 1] == s[*i])
	{
		op = strndup(&s[*i], 2);
		*i += 2;
	}
	else
	{
		op = strndup(&s[*i], 1);
		(*i)++;
	}
	return (op);
}

static char	**split_words(const char *s, char **result, int word_count)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (k < word_count)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (!s[i])
			break;
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

	(void)c; // Il carattere 'c' non è più usato ma mantenuto per la compatibilità.
	if (!s)
		return (0);
	word_count = count_words(s);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (0);
	return (split_words(s, result, word_count));
}
/////////////////////////////////////////////////////

/*
char	**ft_split_with_quotes(const char *str)
{
	char	**tokens = malloc(sizeof(char *) * 256); // Semplificazione
	int		i = 0, k = 0, start = 0;
	bool	in_single_quotes = false, in_double_quotes = false;

	if (!tokens)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"' && !in_single_quotes) // Gestione doppi apici
			in_double_quotes = !in_double_quotes;
		else if (str[i] == '\'' && !in_double_quotes) // Gestione apici singoli
			in_single_quotes = !in_single_quotes;
		else if (str[i] == ' ' && !in_single_quotes && !in_double_quotes) // Spazio fuori apici = fine token
		{
			if (i > start)
				tokens[k++] = strndup(&str[start], i - start);
			while (str[i] == ' ') i++; // Salta spazi multipli
			start = i;
			continue;
		}
		i++;
	}
	if (i > start) // Ultimo token
		tokens[k++] = strndup(&str[start], i - start);
	tokens[k] = NULL;
	return (tokens);
}
*/

