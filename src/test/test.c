#include "../../include/minishell.h"



void testprintf(void)
{
    printf("\n🚨     This is a test_message from testprintf()     🚨\n");
}

void testprintf1(void)
{
    printf("\n🚨     This is a test_message from testprintf1()     🚨\n");
}

void testprintf2(void)
{
    printf("\n🚨     This is a test_message from testprintf2()     🚨\n");
}

void testprintf3(void)
{
    printf("\n🚨     This is a test_message from testprintf3()     🚨\n");
}

void testprintf4(void)
{
    printf("\n🚨     This is a test_message from testprintf4()     🚨\n");
}
/*
void	copy_env(char **src, char ***dst)
{
	int		i;
	char	**tmp;

	i = 0;
	while (src[i])
		i++;
	tmp = (char **)ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (src[i])
	{
		tmp[i] = ft_strdup(src[i]);
		i++;
	}
	*dst = tmp;
}

void	copy_path_and_add_slash(char **src, char ***dst)
{
	int		i;
	char	**tmp;

	i = 0;
	while (src[i])
		i++;
	tmp = (char **)ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (src[i])
	{
		tmp[i] = ft_strjoin(src[i], "/");
		i++;
	}
	*dst = tmp;
}


void	shell_env(char **env, t_shell *shell)
{
	char	**path_env;

	copy_env(env, &shell->env);

	path_env = ft_split(getenv("PATH"), ':');
	copy_path_and_add_slash(path_env, &shell->paths);

	int i = 0;
	while (path_env[i])
	{
		free(path_env[i]);
		i++;
	}
	free(path_env);
}


*/