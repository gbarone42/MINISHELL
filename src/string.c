/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:13 by filippo           #+#    #+#             */
/*   Updated: 2024/01/05 19:45:17 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

char	*ft_strjoin_and_free_first(char *first, char *second)
{
	char	*output;

	output = ft_strjoin(first, second);
	free(first);
	return (output);
}

char	*ft_strjoin_and_free_second(char *first, char *second)
{
	char	*output;

	output = ft_strjoin(first, second);
	free(second);
	return (output);
}

void	ft_set_prompt(t_shell *shell)
{
	char	*output;
	char	*tmp;

	output = ft_strjoin(GREEN, getenv("USER"));
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	output = ft_strjoin_and_free_first(output, "@");
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	output = ft_strjoin_and_free_first(output, BLUE);
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	tmp = getcwd(NULL, 0);
	output = ft_strjoin_and_free_first(output, tmp);
	free(tmp);
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	output = ft_strjoin_and_free_first(output, WHITE "$ ");
	if (!output)
		ft_free_and_err(shell, "ft_strjoin", errno = ENOMEM);
	shell->prompt = output;
}

char	*ft_strdup_decorator(char *str)
{
	if (!str)
		return (NULL);
	return (ft_strdup(str));
}
