/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:32 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/10 18:27:41 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_env(t_shell *shell)
{
	t_evlist	*current ;

	current = shell->env_list;
	while (current)
	{
		printf("%s\n", current->value);
		current = current->next;
	}
}
