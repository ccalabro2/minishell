/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:31:17 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/21 21:27:14 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"


char	**pipe_splitter(char *str, t_main *main)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = ft_pipe_split(str, 124);
	//printf("\n");
	while (matrix[i])
	{
		//printf("token[%d]:%s.\n", i, matrix[i]);
		i++;
	}
	//printf("token[%d]:%s.\n\n", i, matrix[i]);
	main->pipe_number = i;
	return (matrix);
}
