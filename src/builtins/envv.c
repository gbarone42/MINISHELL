/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:32 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/24 14:08:05 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_env(t_shell *shell)
{
	//t_evlist	*current ;
	int i = 0;

	//current = shell->env_list;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		//current = current->next;
		i++;
	}
}
