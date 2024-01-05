#include "../include/minishell.h"

int ft_isvalid(const char *input)
{
    if (input == NULL)
	{
        return 0;
    }
    size_t length = ft_strlen(input);
    if (length == 0 || length > INPUT_SIZE)
	{
        return 0;
    }
    size_t i = 0;
    while (input[i])
	{
        if (input[i] < 32 || input[i] == 127)
		{
            return 0;
        }
        i++;
    }
    return 1;
}
