/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:59:57 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/23 14:38:22 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_term(t_tlist **p_token, int token_type, char **buffer)
{
	t_tlist	*token;

	token = *p_token;
	if (token == NULL)
		return (0);
	*p_token = token->next;
	if (token->type == token_type)
	{
		if (buffer)
			*buffer = ft_strdup(token->data);
		return (1);
	}
	return (0);
}

char	**ft_args(t_tlist **token)
{
	t_tlist	*save;
	size_t	index;
	char	**args;

	save = *token;
	index = 0;
	while (ft_term(token, GENERAL_TOKEN, NULL))
		index++;
	*token = save;
	if (!index)
		return (NULL);
	args = malloc(sizeof(char *) * ++index);
	index = 0;
	while (ft_term(token, GENERAL_TOKEN, &args[index]))
	{
		index++;
		save = *token;
	}
	args[index] = 0;
	*token = save;
	return (args);
}

int	ft_check_grammar(t_tlist **first)
{
	t_tlist	*save;
	int		type;

	save = *first;
	while (save->next)
	{
		type = save->type;
		if (type == PIPE_TOKEN)
		{
			type = save->next->type;
			if (type == PIPE_TOKEN || !type)
				return (*first = save, 0);
		}
		else if (type == GREATER_TOKEN || type == LESSER_TOKEN || \
			type == DGREATER_TOKEN || type == DLESSER_TOKEN)
			if (save->next->type != GENERAL_TOKEN)
				return (*first = save, 0);
		save = save->next;
	}
	*first = save;
	return (1);
}
