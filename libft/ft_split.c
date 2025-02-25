/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:13:13 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/25 12:49:54 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

#include <stdlib.h>

static size_t word_count(const char *s, char c)
{
    size_t count = 0;
    size_t i = 0;

    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

static char *word_dup(const char *s, char c)
{
    size_t len = 0;
    char *word;

    while (s[len] && s[len] != c)
        len++;
    word = malloc(len + 1);
    if (!word)
        return (NULL);
    len = 0;
    while (s[len] && s[len] != c)
    {
        word[len] = s[len];
        len++;
    }
    word[len] = '\0';
    return (word);
}

static void free_split(char **split, size_t i)
{
    while (i > 0)
        free(split[--i]);
    free(split);
}

char **ft_split(const char *s, char c)
{
    size_t i = 0, j = 0;
    char **split;

    if (!s)
        return (NULL);
    split = malloc((word_count(s, c) + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            split[j] = word_dup(s + i, c);
            if (!split[j++])
                return (free_split(split, j - 1), NULL);
            while (s[i] && s[i] != c)
                i++;
        }
    }
    split[j] = NULL;
    return (split);
}
