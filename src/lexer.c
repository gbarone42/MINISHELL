/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:26:35 by filippo           #+#    #+#             */
/*   Updated: 2024/01/04 20:04:34 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static void	ft_print_lexer(t_tlist *token)
{
	int		ntokens;

	ntokens = 0;
	while (token)
	{
		ft_printf("Data: %s\nType: %c\n\n", token->data, token->type);
		token = token->next;
		ntokens++;
	}
	ft_printf("ntokens: %d\n", ntokens);
}

static int	ft_case(t_tlist *token, char c, size_t index, int state)
{
	token->data[index] = c;
	if (c == '$')
		token->expand++;
	if (!index)
	{
		if (c == '\'' || c == '\"')
			token->type = c;
		else
			token->type = GENERAL_TOKEN;
	}
	return (state);
}

static int	ft_case_decorator(t_tlist *token, char c, size_t index, int state)
{
	static t_shell	*shell;

	if (!shell)
		shell = ft_ret_shell(NULL);
	if (c == ft_case(token, c, index, state))
		return (GENERAL_STATE);
	return (state);
}

static int	ft_switch_case(size_t input_len, t_tlist **token, char c, \
	t_dsize_t *i_j)
{
	if (c == '\'' || c == '\"')
		return (ft_case(*token, c, i_j->y++, c));
	else if (c == ' ')
		i_j->y = ft_app_tlist(i_j->y, token, input_len - i_j->x);
	// handle << >> 
	else if (c == '<' || c == '>' || c == '|')
		i_j->y = ft_app_tlist_decorator(i_j->y, token, c, input_len - i_j->x);
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
			state = ft_switch_case(input_len, &token, c, &i_j);
		else if (state == QUOTE_STATE || state == DQUOTE_STATE)
			state = ft_case_decorator(token, c, i_j.y++, state);
	}
//	ft_expand_variables(first);
	ft_print_lexer(first);
	return (first);
}
