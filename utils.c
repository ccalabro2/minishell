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
/*
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10;
		result += (*str++ - '0');
	}
	return (sign * result);
}
*/

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

int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
