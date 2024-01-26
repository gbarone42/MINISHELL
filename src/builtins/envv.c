/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:32 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/26 14:30:38 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_env(t_shell *shell)
{
	char	**env;

	if (shell == NULL || shell->env_list == NULL)
	{
		printf("shell or shell->env is NULL.\n");
		return ;
	}
	env = shell->env_list;
	while (*env)
	{
		if(ft_strnstr(*env, "=", ft_strlen(*env)))
			printf("%s\n", *env);
		env++;
	}
}
