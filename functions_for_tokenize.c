#include "struct.h"

char	*if_is_io_redirection(char *str, char **tokens)
{
	char	buffer[TOKEN_MAX];
	int		token_count;
	int	j;

	j = 0;
	token_count = 0;
	if (j > 0)
	{
		buffer[j] = '\0';
		tokens[token_count] = ft_strdup(buffer);
		token_count++;
		j = 0;
		printf("if_is_special_char1: genera token\n");
		printf("j = %d\n", j);
	}
	return str;
}

char	*if_is_space_tab(char	*str, char **tokens)
{
	char	buffer[TOKEN_MAX];
	int		token_count;
	int		i;

	i = 0;
	token_count = 0;
	if (str[i] != ' ' && str[i] != '\t')/* (str[i] < 9 && str[i] > 32)*/
	{
		buffer[0] = str[i];
		buffer[1] = '\0';
		tokens[token_count] = ft_strdup(buffer);
		token_count++;
		printf("if_is_space_tab: genera token operatore\n");
	}
	return str;
}

char	*if_is_quote(char	*str, char **tokens)
{
	char	quote;
	char	buffer[TOKEN_MAX];
	int		token_count;
	int	i;
	int	j;

	token_count = 0;
	i = 0;
	j = 0;
	quote = str[i++];
	printf("inizio stringa\n");
	while (str[i] && str[i] != quote)
	{
		buffer[j] = str[i];
		j++;
		i++;
	}
	printf("fine stringa\n");
	buffer[j] = '\0';
	tokens[token_count] = ft_strdup(buffer);
	token_count++;
	j = 0;
	return str;
}

char	*if_is_null(char *str, char **tokens, char *buffer)
{
	int		token_count;
	int	i;
	int	j;

	token_count = 0;
	i = 0;
	j = 0;

	buffer[j] = '\0';
	tokens[token_count] = ft_strdup(buffer);
	token_count++;
	j = 0;
	printf("last token\n");
	printf("j = %d\n", j);
}
