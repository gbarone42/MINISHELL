#include "../../include/minishell.h"

int	ft_isvalid(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) < 1 || ft_strlen(s) > INPUT_SIZE)
		return (1);
	while (s[i])
	{
		if (s[i] < 32 && s[i] == 127) //should it be '||' or '&&' //This function's logic needs clarification.
			return (0);
		i++;
	}
	return (1);
}
