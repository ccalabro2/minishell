/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:05:34 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/20 22:56:47 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"




static int	pipe_count_words(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\0' && str[i] != '\"')
				i++;
			if (str[i] == '\"')
			{
				i++;
			}
			else
			{
				return (0);
			}
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
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;

	// while (k < pipe_count)
	// {
	// 	j = 0;
	// 	while (s[i + j])
	// 	{
	// 		if (s[i + j] == '\"')
	// 		{
	// 			j++;
	// 			while(s[i + j] != '\"' || s[i + j] != '\0')
	// 				j++;
	// 		}
	// 		if (s[i + j] == '|')
	// 		{
	// 			j++;
	// 			break;
	// 		}
	// 		j++;
	// 	}
	// 	i = i + j;
	// 	if (!result[k - 1])
	// 		return (free_array(result, k - 1));
	// }
	while (k < pipe_count)
	{
		j = 0;
		while (s[i])
		{
			if (s[i] == '\"')
			{
				i++;
				j++;
				while(s[i] != '\0' && s[i] != '\"')
				{
					i++;
					j++;
				}
			}
			if (s[i] == '|')
			{
				i++;
				j++;
				break;
			}
			i++;
			j++;
		}
		if (s[i] == '\0')
		{
			i++;
			j++;
		}
		result[k] = strndup(s+(i - j), j - 1); //AAA
		k++;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_pipe_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	(void)c; // Il carattere 'c' non è più usato ma mantenuto per la compatibilità.
	if (!s)
		return (0);
	word_count = pipe_count_words(s);
	printf("ecco il numero delle pipe: %d\n", word_count);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (0);
	char **tmp_matrix = pipe_split_words(s, result, word_count);

	int l = 0;
	while(result[l])
	{
		printf("ecco matrix: %s.\n",result[l]);
		l++;
	}


	return (tmp_matrix);

}
