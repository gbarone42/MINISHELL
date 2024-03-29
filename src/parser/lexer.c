/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:26:35 by filippo           #+#    #+#             */
/*   Updated: 2024/01/26 20:04:17 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_remove_quotes(t_tlist *token)
{
	char		*data;
	t_dsize_t	src_dest_index;
	char		c;
	char		control;

	while (token)
	{
		data = token->data;
		src_dest_index = (t_dsize_t){0, 0};
		control = 0;
		c = data[src_dest_index.x++];
		while (c)
		{
			if ((c == '\"' || c == '\'') && !control)
				control = c;
			else if (c == control)
				control = 0;
			else
				data[src_dest_index.y++] = c;
			c = data[src_dest_index.x++];
		}
		data[src_dest_index.y] = '\0';
		token = token->next;
	}
}

static int	ft_case(t_tlist *token, char c, size_t index, int state)
{
	char	*data;

	data = token->data;
	data[index] = c;
	if (state != QUOTE_STATE && c == '$')
		ft_app_ilist(&token->expand, index);
	if (!index)
		token->type = GENERAL_TOKEN;
	return (state);
}

static int	ft_case_decorator(t_tlist *token, char c, size_t *index, int state)
{
	if (c == ft_case(token, c, (*index)++, state))
		return (GENERAL_STATE);
	return (state);
}

static int	ft_switch(size_t input_len, t_tlist **token, char c, \
	t_dsize_t *i_j)
{
	if (c == '\'' || c == '\"')
		return (ft_case(*token, c, i_j->y++, c));
	else if (c == ' ' || c == '\t')
		i_j->y = ft_app_tlist(i_j->y, token, input_len - i_j->x);
	else if (c == '<' || c == '>' || c == '|' || c == '\n')
		i_j->y = ft_app_tlist_decorator(i_j, token, c, input_len - i_j->x);
	else
		ft_case(*token, c, i_j->y++, GENERAL_STATE);
	return (GENERAL_STATE);
}

t_tlist	*ft_lexer(t_shell *shell, char *input, size_t input_len, int state)
{
	t_tlist		*first;
	t_tlist		*token;
	t_dsize_t	i_j;
	char		c;

	first = ft_new_tlnode(input_len);
	if (!first)
		ft_free_and_err(shell, "FT_NEW_TLNODE", errno = ENOMEM);
	token = first;
	i_j = (t_dsize_t){0, 0};
	while (state)
	{
		c = input[i_j.x++];
		if (c == '\0')
			state = ft_app_tlist(i_j.y, &token, 0);
		else if (state == GENERAL_STATE)
			state = ft_switch(input_len, &token, c, &i_j);
		else if (state == QUOTE_STATE || state == DQUOTE_STATE)
			state = ft_case_decorator(token, c, &i_j.y, state);
	}
	ft_expand_env_var(first, (t_dsize_t){0, 0}, 0);
	ft_remove_quotes(first);
	return (first);
}
