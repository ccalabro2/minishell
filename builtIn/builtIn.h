/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtIn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:54:08 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/21 20:01:23 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
#define BUILT_IN_H

#include "../struct.h"

void    print_env(char **env);
void    builtin_export(char ***env, const char *key, const char *value);
void    builtin_unset(char ***env, const char *key);
void    ft_exit();
void    ft_pwd();
void    ft_cd(int argc, char **argv);
void	ft_echo(int argc, char **argv);


#endif
