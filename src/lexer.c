/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:26:35 by filippo           #+#    #+#             */
/*   Updated: 2024/01/05 00:28:30 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"
#include "lexer_p.h"

static void	ft_print_lexer(t_tlist *token)
{
	int		ntokens;
	t_ilist	*expand;

	ntokens = 0;
	while (token)
	{
		ft_printf("Data: %s\nType: %d\nExpand: ", token->data, token->type);
		expand = token->expand;
		token = token->next;
		ntokens++;
		if (!expand)
		{
			ft_printf("\n\n");
			continue ;
		}
		while (expand->next)
		{
			ft_printf("%d, ", expand->index);
			expand = expand->next;
		}
		ft_printf("%d\n\n", expand->index);
	}
	ft_printf("ntokens: %d\n", ntokens);
}

static int	ft_case(t_tlist *token, char c, size_t index, int state)
{
	token->data[index] = c;
	if (state != QUOTE_STATE && c == '$')
		ft_app_ilist(&token->expand, index);
	if (!index)
		token->type = GENERAL_TOKEN;
	return (state);
}

static int	ft_case_decorator(t_tlist *token, char c, size_t *index, int state)
{
	if (c == state)
		return (GENERAL_STATE);
	return (ft_case(token, c, (*index)++, state));
}

static int	ft_switch(size_t input_len, t_tlist **token, char c, \
	t_dsize_t *i_j)
{
	if (c == '\'' || c == '\"')
		return (c);
	else if (c == ' ' || c == '\t')
		i_j->y = ft_app_tlist(i_j->y, token, input_len - i_j->x);
	else if (c == '<' || c == '>' || c == '|')
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
//	ft_expand_variables(first);
	ft_print_lexer(first);
	return (first);
}
