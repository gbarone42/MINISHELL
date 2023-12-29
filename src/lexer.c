/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:26:35 by filippo           #+#    #+#             */
/*   Updated: 2023/12/29 11:52:09 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

static void	ft_print_lexer(t_shell *shell)
{
	t_tlist	*tokens;

	tokens = shell->tokens;
	while (tokens)
	{
		ft_printf("Data: %s\n\n", tokens->data);
		tokens = tokens->next;
	}
	ft_printf("ntokens: %d\n", shell->ntokens);
}

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
	return (state);
}

static int	ft_switch_case(size_t input_len, t_tlist **token, char *p_c_state, \
	t_dsize_t *i_j)
{
	char			c;

	c = *p_c_state;
	if (c == '\'')
		*p_c_state = ft_case(*token, c, i_j->y++, QUOTE_STATE);
	else if (c == '\"')
		*p_c_state = ft_case(*token, c, i_j->y++, DQUOTE_STATE);
	else if (c == ' ')
		i_j->y = ft_app_tlist(i_j->y, token, input_len - i_j->x);
	else if (c == '<' || c == '>' || c == '|')
		i_j->y = ft_app_tlist_decorator(i_j->y, token, c, input_len - i_j->x);
	else
		*p_c_state = ft_case(*token, c, i_j->y++, GENERAL_STATE);
	return (*p_c_state != c);
}

void	ft_lexer(t_shell *shell, char *input, size_t input_len, int state)
{
	t_tlist		*token;
	t_dsize_t	i_j;
	char		c;

	token = ft_new_tlnode(input_len);
	if (!token)
		ft_free_and_err(shell, "FT_NEW_TLNODE", errno = ENOMEM);
	shell->tokens = token;
	i_j = (t_dsize_t){0, 0};
	while (state)
	{
		c = input[i_j.x++];
		if (c == '\0')
			state = ft_app_tlist(i_j.y, &token, 0);
		else if (state == GENERAL_STATE
			&& ft_switch_case(input_len, &token, &c, &i_j))
			state = c;
		else if (state == QUOTE_STATE || state == DQUOTE_STATE)
			state = ft_case_decorator(token, c, i_j.y++, state);
	}
	ft_print_lexer(shell);
}
