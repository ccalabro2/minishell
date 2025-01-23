
#include "struct.h"

/*int is_space(char c)
{
	if (c > 0 && c <= 32)
		return 1;
	return 0;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(is_space(*--back));
    *(back+1) = '\0';
    return s;
}
*/
char **tokenize(char *input)
{
	char    **tokens;
	char    quote;
	char buffer [TOKEN_MAX];
	//input = rtrim(input);
	int i;
	int j;
	int token_count;

	i = 0;
	j = 0;
	token_count = 0;
	tokens = malloc(sizeof(char *) * TOKEN_MAX);

	if (!tokens)
		return NULL;
	while (input[i])
	{
		// TODO: al posto di \t includere tutti i tipi di spazi/tab
		if (input[i] == '\t' || input[i] == ' ' || input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			if (j > 0)
			{
				buffer[j] = '\0';
				tokens[token_count] = strdup(buffer);
				token_count++;
				j = 0;
				printf("genera token\n");
				printf("j = %d\n", j);
			}
			if (input[i] != ' ' && input[i] != '\t')
			{

				buffer[0] = input[i];
				buffer[1] = '\0';
				tokens[token_count] = strdup(buffer);
				token_count++;
				printf("genera token operatore\n");
			}
		}
		else if (input[i] == '\'' || input[i] == '\"')
		{
			quote = input[i++];
			printf("inizio stringa\n");
			while (input[i] && input[i] != quote)
			{
				buffer[j] = input[i];
				j++;
				i++;
			}
			printf("fine stringa\n");
			buffer[j] = '\0';
			tokens[token_count] = strdup(buffer);
			token_count++;
			j = 0;
		}
		else
		{
			buffer[j] = input[i];
			j++;
			printf("j = %d\n", j);
		}
		i++;
	}

	if (input[i] == '\0' && input[--i] != ' ')
	{
		buffer[j] = '\0';
		tokens[token_count] = strdup(buffer);
		token_count++;
		j = 0;
		printf("last token\n");
		printf("j = %d\n", j);
	}
	
	return tokens;
}
