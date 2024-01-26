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

void	process_env_variable(t_shell *shell, char *arg)
{
	char	*name;
	char	*value;

	name = ft_strtok(arg, '=');
	value = ft_strtok(NULL, '=');
	if (name != NULL)
	{
		if (contains_invalid_characters(name))
			printf("Invalid variable name: %s\n", name);
		else
		{
			if (value == NULL)
			{
				add_envv_variable(shell, name, "");
			}
			else
			{
				add_env_variable(shell, name, value);
			}
		}
	}
	else
		printf("Invalid export syntax: %s\n", arg);
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
