/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exv_std_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:22:52 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/21 20:19:21 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void    manager_tools(t_exec_manager *tools)
{
	tools->pipe_std_in = -1;
	tools->pipe_std_out = -1;
    tools->old_fd[0] = -1;
	tools->old_fd[1] = -1;
    tools->fd[0] = -1;
	tools->fd[1] = -1;
}
