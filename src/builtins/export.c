/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sdel-gra <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/10 16:30:40 by gbarone		   #+#	#+#			 */
/*   Updated: 2024/02/07 15:24:50 by filippo          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

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
	if (!args[1])
		ft__env(shell, "declare -x ", 1);
	else
		process_env_variable(shell, args[1]);
}
