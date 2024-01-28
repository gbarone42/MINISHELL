/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   export_unset.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sdel-gra <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/10 16:30:40 by gbarone		   #+#	#+#			 */
/*   Updated: 2024/01/25 21:54:56 by sdel-gra		 ###   ########.fr	   */
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

void	handle_export(t_shell *shell, char **args)
{
	if (args[1] == NULL)
	{
		handle_envv(shell);
	}
	else
	{
		process_env_variable(shell, args[1]);
	}
}
