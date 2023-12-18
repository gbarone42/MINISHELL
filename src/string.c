/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:13 by filippo           #+#    #+#             */
/*   Updated: 2023/12/18 23:40:12 by filippo          ###   ########.fr       */
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

char	*ft_set_prompt(char *user)
{
	char	*output;
	char	*tmp;

	output = ft_strjoin(GREEN, user);
	output = ft_strjoin_decorator(output, "@");
	output = ft_strjoin_decorator(output, BLUE);
	tmp = getcwd(NULL, 0);
	output = ft_strjoin_decorator(output, tmp);
	free(tmp);
	output = ft_strjoin_decorator(output, WHITE "$ ");
	return (output);
}
