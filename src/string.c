/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:13 by filippo           #+#    #+#             */
/*   Updated: 2023/12/29 11:55:45 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

char	*ft_strjoin_decorator(char *first, char *second)
{
	char	*output;

	output = ft_strjoin(first, second);
	free(first);
	return (output);
}

void	ft_set_prompt(t_shell *shell)
{
	char	*output;
	char	*tmp;

	output = ft_strjoin(GREEN, getenv("USER"));
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	output = ft_strjoin_decorator(output, "@");
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	output = ft_strjoin_decorator(output, BLUE);
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	tmp = getcwd(NULL, 0);
	output = ft_strjoin_decorator(output, tmp);
	free(tmp);
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	output = ft_strjoin_decorator(output, WHITE "$ ");
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	shell->prompt = output;
}
