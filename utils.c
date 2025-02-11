/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:47:43 by ccalabro          #+#    #+#             */
/*   Updated: 2025/02/11 15:18:22 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	init(t_cmd *cmd)
{
	cmd->command = NULL;
	cmd->args = malloc(sizeof(char *) * TOKEN_MAX);
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->flag = 0;
	if (!cmd)
		return ;
}

char *trim_quotes(char *str)
{
    int i;
	int j;

	j = 0;
	i = 0;

    while (str[i])
	{
        if (str[i] != '\'' && str[i] != '\"')
		{
            str[j] = str[i];
            j++;
        }
        i++;
    }
	return (str);
}



char	*ft_strdup(const char	*src)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	enddest;
	size_t	endsrc;
	size_t	i;

	i = 0;
	endsrc = ft_strlen(src);
	if (size == 0 || size <= ft_strlen(dest))
		return (size + endsrc);
	enddest = ft_strlen(dest);
	while (i < size - enddest - 1 && src[i])
	{
		dest[i + enddest] = src[i];
		i++;
	}
	dest[i + enddest] = '\0';
	return (enddest + endsrc);
}
