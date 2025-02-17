/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:32:56 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/17 14:43:22 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void ft_echo(char **str)
{
    int i;
    int newline;

    i = 1;
    newline = 1;
    while(str[i] && ft_strcmp(str[i], "-n") == 0)
    {
        newline = 0;
        i++;
    }
    while (str[i])
    {
        write(1, str[i], ft_strlen(str[i]));
        if (str[i + 1])
            write(1, " ", 1);
        i++;
    }
    if (newline == 1)
        write(1, "\n", 1);
}
