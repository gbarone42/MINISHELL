/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:32 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/26 17:11:56 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_env(t_shell *shell)
{
	char	**env;

	if (shell == NULL || shell->env == NULL)
	{
		printf("shell or shell->env is NULL.\n");
		return ;
	}
	env = shell->env;
	while (*env)
	{
		if (ft_strnstr(*env, "=", ft_strlen(*env)))
			printf("%s\n", *env);
		env++;
	}
}
