/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:17:55 by fcorri            #+#    #+#             */
/*   Updated: 2024/02/02 18:22:43 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_no_assignment(char *arg, t_shell *shell)
{
	char	*var;

	var = ft_strdup(arg);
	if (compare_env_vars(var, shell->env_list))
	{
		free(var);
		return (1);
	}
	free(var);
	return (-1);
}

int	control_exist(char **arg, t_shell *shell)
{
	int	result;

	if (!contains_assignment_operator(*arg))
	{
		result = handle_no_assignment(*arg, shell);
	}
	else
	{
		result = handle_assignment_present(shell->input, shell);
	}
	if (result != -1)
	{
		return (result);
	}
	return (0);
}
