/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:32 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/24 19:05:14 by gbarone          ###   ########.fr       */
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

// void handle_env(t_shell *shell)
// {
//     char **env = shell->env;
//     while (*env)
//     {
//         printf("%s\n", *env);
//         env++;
//     }
// }
// void	handle_env(t_shell *shell)
// {
// 	//t_evlist	*current ;
// 	int i = 0;

// 	//current = shell->env_list;
// 	while (shell->env[i])
// 	{
// 		printf("%s\n", shell->env[i]);
// 		//current = current->next;
// 		i++;
// 	}
// }
