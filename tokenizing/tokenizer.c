#include "struct.h"

char **tokenize(const char *input)
{
    char    **tokens;
    char    *quote;
    char    *buffer;
    int i;
    int j;
    int token_count;

    i = 0;
    j = 0;
    buffer = TOKEN_MAX;
    token_count = 0;
    tokens = malloc(sizeof(char *) * TOKEN_MAX);

    if (!tokens)
        return NULL;
    while (input[i])
    {
        if (input[i] == ' ' || input[i] == '|' || input[i] == '<' || input[i] == '>')
        {
            if (j > 0) 
            {
                buffer[j] = '\0';
                tokens[token_count] = strdup(buffer);
                token_count++;
                j = 0;
            }
            if (input[i] != ' ')
            {
                buffer[0] = input[i];
                buffer[1] = '\0';
                tokens[token_count] = strdup(buffer);
                token_count++;
            }
        }
        else if (input[i] == '\'' || input[i] == '\"')
        {
            quote = input[i++];
            while (input[i] && input[i] != quote)
            {
                buffer[j] = input[i];
                j++;
                i++;
            }
            buffer[j] = '\0';
            tokens[token_count] = strdup(buffer);
            token_count++;
            j = 0;
        }
        else 
        {
            buffer[j] = input[i];
            j++;
        }
        i++;
    }
    if (j > 0)
    {
        buffer[j] = '\0';
        tokens[token_count] = strdup(buffer);
    }
    tokens[token_count] = NULL;
    return tokens;
}
