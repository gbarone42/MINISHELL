/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:13 by filippo           #+#    #+#             */
/*   Updated: 2024/01/23 15:18:01 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		ft_free_and_err(shell, "FT_STRJOIN", errno = ENOMEM);
	output = ft_strjoin_and_free_first(output, "@");
	if (!output)
		ft_free_and_err(shell, "FT_STRJOIN", errno = ENOMEM);
	output = ft_strjoin_and_free_first(output, BLUE);
	if (!output)
		ft_free_and_err(shell, "FT_STRJOIN", errno = ENOMEM);
	tmp = getcwd(NULL, 0);
	output = ft_strjoin_and_free_first(output, tmp);
	free(tmp);
	if (!output)
		ft_free_and_err(shell, "FT_STRJOIN", errno = ENOMEM);
	output = ft_strjoin_and_free_first(output, WHITE "$ ");
	if (!output)
		ft_free_and_err(shell, "FT_STRJOIN", errno = ENOMEM);
	shell->prompt = output;
}

void	ft_print_char_p(char **p)
{
	size_t	index;
	char	*value;

	index = 0;
	if (!p)
	{
		printf("\n");
		return ;
	}
	value = p[index++];
	while (value)
	{
		printf("%s ", value);
		value = p[index++];
	}
	printf("\n");
}
