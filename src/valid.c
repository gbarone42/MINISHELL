#include "../include/minishell.h"



int ft_isvalid(const char *input)
{
    if (input == NULL)
	{
        return 0; // Invalid input
    }
    size_t length = ft_strlen(input);
    if (length == 0 || length > INPUT_SIZE)
	{
        return 0; // Invalid input due to length constraints
    }
    size_t i = 0; // Declare i once
    while (input[i])
	{
        if (input[i] < 32 || input[i] == 127)
		{ // Use logical OR to check for control characters
            return 0;
        }
        i++;
    }
    return 1; // Input is valid
}

