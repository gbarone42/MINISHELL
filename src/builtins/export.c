/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sdel-gra <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/10 16:30:40 by gbarone		   #+#	#+#			 */
/*   Updated: 2024/02/08 20:55:49 by fcorri           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_and_exit_status(char *ft, int ret)
{
	perror(ft);
	g_exit = 1;
	return (ret);
}

int	ft_env_len(char **env, char ***new_env)
{
	int	len;

	len = 0;
	while (*env++)
		len++;
	*new_env = ft_calloc(len + 1, sizeof(char *));
	if (!*new_env)
		return (ft_error_and_exit_status("export", -1));
	return (len);
}

int	ft_add_var(t_shell *shell, char *arg, char **env, char **new_env)
{
	int		flag;
	int		index;

	if (ft_env_len(env, &new_env) == -1)
		return (ft_error_and_exit_status("export", 1));
	env = shell->env;
	index = -1;
	flag = 0;
	while (env[++index])
	{
		if (!ft_strncmp(env[index], arg, ft_strchr(arg, '=') - arg))
		{
			free(env[index]);
			new_env[index] = arg;
			flag = 1;
		}
		else
			new_env[index] = env[index];
	}
	new_env[index] = NULL;
	if (flag == 0)
		new_env[index] = ft_strdup(arg);
	free(shell->env);
	shell->env = new_env;
	return (0);
}

void	free_arr(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	ft__export(t_shell *shell, char **args)
{
	char	*arg;
	int		index;

	if (!args[1])
		ft__env(shell, "declare -x ", 1);
	else
	{
		index = 1;
		while (args[index])
		{
			arg = args[index++];
			if (ft_strchr(arg, '='))
				ft_add_var(shell, arg, shell->env, NULL);
		}
	}
	g_exit = 0;
}
