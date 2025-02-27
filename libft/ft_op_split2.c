/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_split2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:10:18 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/27 14:36:52 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char	*extract_word(const char *s, int *i)
{
	int	start;

	start = *i;
	while (s[*i] && !is_operator(s[*i]) && s[*i] != ' ' && s[*i] != '\t')
	{
		(*i)++;
	}
	return (strndup(&s[start], *i - start));
}

char	*extract_quotes(const char *s, int *i)
{
	int	start;

	start = *i;
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		(*i)++;
	}
	return (strndup(&s[start], *i - start));
}

char	*extract_operator(const char *s, int *i)
{
	char	*op;

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

void	count_word_check(const char *str, int *i, int *count)
{
	if (is_operator(str[*i]))
	{
		(*count)++;
		if ((str[*i] == '<' || str[*i] == '>') && str[*i + 1] == str[*i])
			(*i)++;
		(*i)++;
	}
	else if (str[*i] == '\"')
	{
		(*i)++;
		while (str[*i] != '\0' && str[*i] != '\"')
			(*i)++;
		if (str[*i] == '\"')
			(*i)++;
		(*count)++;
	}
	else
	{
		(*count)++;
		while (str[*i] && !is_operator(str[*i])
			&& str[*i] != ' ' && str[*i] != '\t')
			(*i)++;
	}
}
