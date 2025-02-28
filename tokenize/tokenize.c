/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:00:57 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/28 11:45:40 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	build_cmdarray(t_main *main)
{
	main->cmdarray = ft_calloc(main->pipe_number + 1, sizeof(t_cmd));
	if (!main->cmdarray)
	{
		printf("Errore: malloc fallita in build_fun\n");
		exit(EXIT_FAILURE);
	}
}

void	parser(char *str, t_cmd *elment_array, int index)
{
	int		i;
	int		k;
	char	**matrix;

	k = 0;
	i = 0;
	matrix = ft_op_split(str, ' ');
	int z = 0;
	while (matrix[z])
	{
		z++;
	}
	check_parser(&matrix, elment_array, index);
	while (matrix[i])
	{
		check_parser_two(matrix, elment_array, &i, &k);
	}
	elment_array->args[k] = NULL;
	elment_array->argc = k;
	if (elment_array->args[0])
		elment_array->command = elment_array->args[0];
	else
		elment_array->command = "";
	free(matrix);
}

void	tokenize(char *inputstr, t_main *main)
{
	int		i;
	char	**input_matrix;
	char	*expanded_str;

	i = 0;
	input_matrix = pipe_splitter(inputstr, main);
	if (!input_matrix)
	{
		printf("Errore: pipe_splitter ha restituito NULL\n");
		return ;
	}
	build_cmdarray(main);
	while (i < main->pipe_number)
	{
		expanded_str = expand_variables(input_matrix[i], true, true);
		main->cmdarray[i].start = main;
		parser(expanded_str, &main->cmdarray[i], i);
		free(expanded_str);
		i++;
	}
	int t = 0;
	while (main->cmdarray->args[t])
	{
		printf("%s.\n", main->cmdarray->args[t]);


		t++;
	}
	free(input_matrix);
}

void	check_parser(char ***matrix, t_cmd *elment_array, int index)
{

	if (!matrix)
	{
		printf("Errore: ft_op_split ha restituito NULL\n");
		return ;
	}
	if (elment_array->args)
		free(elment_array->args);
	elment_array->args = malloc(sizeof(char *) * 250);
	if (!elment_array->args)
	{
		printf("Errore: malloc fallita per args\n");
		free(matrix);
		return ;
	}
	if (index > 0)
		elment_array->input = PIPE_IN;
	if (index < elment_array->start->pipe_number - 1)
		elment_array->output = PIPE_OUT;
}

void	check_parser_two(char **matrix, t_cmd *elment_array, int *i, int *k)
{
	if (ft_strcmp(matrix[(*i)], "<") == 0)
	{
		if (matrix[(*i) + 1])
			elment_array->input = ft_strdup(matrix[++(*i)]);
	}
	else if (ft_strcmp(matrix[(*i)], ">") == 0)
	{
		if (matrix[(*i) + 1])
		{
			elment_array->output = ft_strdup(matrix[++(*i)]);
			elment_array->flag = 1;
		}
	}
	else if (ft_strcmp(matrix[(*i)], ">>") == 0)
	{
		if (matrix[(*i) + 1])
		{
			elment_array->output = ft_strdup(matrix[++(*i)]);
			elment_array->flag = 0;
		}
	}
	else
		elment_array->args[(*k)++] = matrix[(*i)];
	(*i)++;
}
