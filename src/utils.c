/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:32:28 by fcorri            #+#    #+#             */
/*   Updated: 2024/02/05 17:41:21 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*ft_ret_shell(t_shell *p_shell)
{
	static t_shell	*shell;

	if (!shell)
		shell = p_shell;
	return (shell);
}

void	ft_err(char *caller, int error)
{
	perror(caller);
	exit(error);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (0);
		else
			return (1);
	}
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isvalid(const char *input)
{
	size_t	length;
	size_t	i;
	char	c;

	length = ft_strlen(input);
	if (length > INPUT_SIZE)
		return (0);
	i = 0;
	c = input[i++];
	while (c)
	{
		if (c < 32 || c == 127)
			return (0);
		c = input[i++];
	}
	return (1);
}
