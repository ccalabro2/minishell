/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:10:39 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/21 20:10:49 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t i = 0;
    size_t j = 0;
    char *res;

    if (!s1 || !s2)
        return (NULL);
    res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return (NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    return (res);
}
