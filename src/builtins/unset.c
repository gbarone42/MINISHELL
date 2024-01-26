

#include "minishell.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
	{
		return (char *)haystack;
	}
	const char *p = haystack;
	while (*p != '\0')
	{
		const char *begin = p;
		const char *pattern = needle;
		while (*begin != '\0' && *pattern != '\0' && *begin == *pattern)
		{
			begin++;
			pattern++;
		}
		if (*pattern == '\0')
		{
			return (char *) p;
		}
		p++;
	}
	return (NULL);
}

void	remove_env_variable(t_shell *shell, const char *var_name)
{
	int j, k;
	
	j = 0;
	while (shell->env_list[j] != NULL)
	{
		if (ft_strstr(shell->env_list[j], var_name) == shell->env_list[j])
		{
			printf("Unsetting: %s\n", shell->env_list[j]);
			free(shell->env_list[j]);
			k = j;
			while (shell->env_list[k] != NULL)
			{
				shell->env_list[k] = shell->env_list[k + 1];
				k++;
			}
			shell->env_list[k - 1] = NULL;

			break;
		}
		j++;
	}
}

void handle_unset(t_shell *shell, char **args)
{
	int i;

	if (args[1] == NULL)
	{
		printf("Usage: unset <variable>\n");
		return;
	}
	i = 1;
	while (args[i] != NULL)
	{
		remove_env_variable(shell, args[i]);
		i++;
	}
}
