/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtInEnv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:51:55 by fluzi             #+#    #+#             */
/*   Updated: 2025/03/01 16:03:48 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	print_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
	exit(0);
}

void	builtin_export(char ***env, const char *key)
{
	char	**split_prompt;

	split_prompt = ft_split(key, '=');
	if (set_env_value(env, split_prompt[0], split_prompt[1]) == -1)
	{
		perror("export: failed to set \n");
	}
}

void	builtin_unset(char ***env, const char *key)
{
	if (!key)
	{
		printf ("unset: missing argument\n");
		return ;
	}
	if (unset_env_value(env, key) == -1)
	{
		printf ("unset: `%s` not found\n", key);
	}
}
