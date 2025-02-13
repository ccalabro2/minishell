#include "struct.h"

char **pipe_splitter(char *str)
{
    char	**matrix;

    matrix = ft_split(str, 124);
    return (matrix);
}

/*size_t count_pipe(char **matrix)
{
	size_t	i;
	
	i = 0;
	while (matrix[i])
		i++;
	return(i);
}*/