/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtIn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:52 by fluzi             #+#    #+#             */
/*   Updated: 2025/02/27 16:59:22 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

void	ft_exit(void)
{
	exit(g_exit);
}

static void cd_short(char *cwd, char *oldpwd, char *path)
{
    if (!oldpwd)
    {
        return(printf("getcwd\n"), exit(EXIT_FAILURE));
    }
    if (chdir(path) == -1)
    {
        fprintf(stderr, "cd: %s: %s\n", path, strerror(errno));
        free(oldpwd);
        return;
    }
    if (setenv("OLDPWD", oldpwd, 1) == -1)
    {
        free(oldpwd);
        printf("setenv OLDPWD\n");
        exit(EXIT_FAILURE);
    }
    free(oldpwd);
    if (getcwd(cwd, 1024) == NULL)
        return(printf("getcwd\n"), exit(EXIT_FAILURE));
    if (setenv("PWD", cwd, 1) == -1)
    {
        printf("setenv PWD\n");
        exit(EXIT_FAILURE);
    }
}

void	ft_cd(int argc, char **argv)
{
	char	cwd[1024];
	char	*oldpwd;
	char	*path;

	if (argc < 2)
	{
		path = getenv("HOME");
		if (!path)
			return (printf("cd: HOME not set\n"), exit(EXIT_FAILURE));
	}
	else
	{
		path = argv[1];
		if (strcmp(path, "-") == 0)
		{
			path = getenv("OLDPWD");
			if (!path)
				return (printf("d: OLDPWD not set\n"), exit(EXIT_FAILURE));
			printf("%s\n", path);
		}
	}
	oldpwd = getcwd(NULL, 0);
	cd_short(cwd, oldpwd, path);
}

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	printf("%s \n", cwd);
	exit(0);
}
