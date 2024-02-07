/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:17:55 by fcorri            #+#    #+#             */
/*   Updated: 2024/02/07 16:22:10 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_no_assignment(char *arg, t_shell *shell)
{
	char	*var;

	var = ft_strdup(arg);
	if (compare_env_vars(var, shell->env))
	{
		free(var);
		return (1);
	}
	free(var);
	return (-1);
}

int	control_exist(char **arg, t_shell *shell)
{
	if (!ft_strchr(arg[1], '='))
		return (handle_no_assignment(*arg, shell));
	else
		return (handle_assignment_present(shell->input, shell));
}
