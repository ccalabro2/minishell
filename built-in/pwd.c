/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:45:07 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/17 15:04:48 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

int ft_pwd(void)
{
    char    cwd[PATH_MAX];
    
    if (getcwd(cwd, sizeof(cwd) == NULL))
    {
        perror("an error occured with pwd");
        return 1;
    }
    write(1, cwd, ft_strlen(cwd));
    write(1, "\n", 1);
    return 0;
}
