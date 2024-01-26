#include "minishell.h"

void	handle_envv(t_shell *shell)
{
	char	**env;

	env = shell->env_list;
	while (*env)
	{
		printf("declare -x %s\n", *env);
		env++;
	}
}

bool contains_invalid_characters(const char *str)
{
	int i;
	i = 0;
	if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))
	{
		return (true);
	}
	i = 1;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
		{
			return (true);
		}
		i++;
	}
	return (false);
}