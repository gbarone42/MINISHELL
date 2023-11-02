#include "../../include/minishell.h"

int	ft_isvalid(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) < 1 || ft_strlen(s) > INPUT_SIZE)
		return (0);
	while (s[i])
	{
		if (s[i] < 32 && s[i] == 127) //should it be '||' or '&&'
			return (1);
		i++;
	}
	return (0);
}
