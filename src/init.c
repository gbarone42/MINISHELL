/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:42:17 by filippo           #+#    #+#             */
/*   Updated: 2023/12/18 23:05:58 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static char	**ft_copy_env(char **env)
{
	char	**output;
	int		i;
	int		j;

	i = 0;
	if (env)
		while (env[i])
			i++;
	output = malloc(sizeof(char *) * (i + 1));
	if (!output)
		ft_err("ft_copy_env", errno = ENOMEM);
	j = -1;
	while (++j < i)
	{
		output[j] = ft_strdup(env[j]);
		if (!output[j])
		{
			while (j >= 0)
				free(output[j--]);
			free(output);
			ft_err("ft_copy_env", errno = ENOMEM);
		}
	}
	output[i] = NULL;
	return (output);
}

void	ft_init_shell(t_shell *shell, char **env)
{
	void	*tmp;

	tmp = ft_copy_env(env);
	if (!tmp)
		ft_err("ft_copy_env", errno = ENOMEM);
	shell->env = tmp;
	tmp = getenv("USER");
	if (!tmp)
		ft_free_and_err(shell, "getenv", errno = ENOMEM);
	shell->prompt = ft_set_prompt(tmp);
	if (!shell->prompt)
		ft_free_and_err(shell, "ft_prompt", errno = ENOMEM);
}
