/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:23:38 by gd-auria          #+#    #+#             */
/*   Updated: 2025/02/11 17:24:02 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../struct.h"

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
