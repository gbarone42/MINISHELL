/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:59:57 by fcorri            #+#    #+#             */
/*   Updated: 2024/02/06 13:18:40 by filippo          ###   ########.fr       */
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

char	**ft_args_2(char **old_args, t_tlist **token, t_tlist *save)
{
	t_dsize_t	i_j;
	char		**args;

	save = *token;
	i_j = (t_dsize_t){0, 0};
	while (ft_term(token, GENERAL_TOKEN, NULL))
		i_j.x++;
	*token = save;
	if (!i_j.x)
		return (old_args);
	while (old_args[i_j.y++])
		i_j.x++;
	args = ft_calloc(1, sizeof(char *) * ++i_j.x);
	i_j = (t_dsize_t){0, 0};
	while (old_args[i_j.y])
		args[i_j.x++] = old_args[i_j.y++];
	free(old_args);
	while (ft_term(token, GENERAL_TOKEN, &args[i_j.x++]))
		save = *token;
	args[i_j.x - 1] = NULL;
	*token = save;
	return (args);
}

char	**ft_args_1(t_tlist **token)
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
	args = ft_calloc(1, sizeof(char *) * ++index);
	index = 0;
	while (ft_term(token, GENERAL_TOKEN, &args[index++]))
		save = *token;
	args[index - 1] = NULL;
	*token = save;
	return (args);
}

int	ft_check_grammar(t_tlist **first)
{
	t_tlist	*save;
	int		type;

	save = *first;
	if (save->type == PIPE_TOKEN)
		return (*first = save, 0);
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
