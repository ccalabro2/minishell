/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_split2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:10:18 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/26 16:17:20 by gd-auria         ###   ########.fr       */
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
