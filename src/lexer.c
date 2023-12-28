/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:26:35 by filippo           #+#    #+#             */
/*   Updated: 2023/12/28 01:46:18 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static int	ft_case(t_tlist *token, char c, size_t index, int state)
{
	token->data[index] = c;
	if (!index)
		token->type = GENERAL_TOKEN;
	return (state);
}

static int	ft_case_decorator(t_tlist *token, char c, size_t index, int state)
{
	if (c == ft_case(token, c, index, state))
		return (GENERAL_STATE);
	return state;
}

void	ft_lexer(t_shell *shell, char *input, size_t input_len, int state)
{
	t_tlist				*token;
	char				c;
	static t_dsize_t	i_j;

	token = ft_new_tlnode(input_len);
	if (!token)
		ft_free_and_err(shell, "FT_NEW_TLNODE", errno = ENOMEM);
	shell->tokens = token;
	c = input[i_j.x++];
	while (state)
	{
		if (c == '\0')
			state = ft_append_tlist(shell, i_j.y, &token, 0);
		else if (state == GENERAL_STATE)
		{
			if (c == '\'')
				state = ft_case(token, c, i_j.y++, QUOTE_STATE);
			else if (c == '\"')
				state = ft_case(token, c, i_j.y++, DQUOTE_STATE);
			else if (c == ' ')
				// input_len - i_j.x - 1
				i_j.y = ft_append_tlist(shell, i_j.y, &token, input_len - i_j.x);
			else if (c == '<' || c == '>' || c == '|')
				i_j.y = ft_append_tlist_decorator(shell, (t_dsize_t){i_j.y, input_len - i_j.x}, &token, c);
			else
				state = ft_case(token, c, i_j.y++, GENERAL_STATE);
		}
		else if (state == QUOTE_STATE || state == DQUOTE_STATE)
			state = ft_case_decorator(token, c, i_j.y++, state);
		c = input[i_j.x++];
	}
}
