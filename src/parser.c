/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:16:03 by filippo           #+#    #+#             */
/*   Updated: 2024/01/05 00:28:39 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	<command line>		::=		<job>

	<job>				::=		<command>
							|	<job> '|' <command>

	<command>			::=		<simple command>
							|	<command> '<' <filename>
							|	<command> '>' <filename>
							|	<command> '<<' <filename>
							|	<command> '>>' <filename>

	<simple command>	::=		<pathname> <token list>

	<token list>		::=		<token> <token list>
							|	EMPTY
 */

#include "minishell_p.h"
#include "lexer_p.h"

t_clist	*ft_parser(t_shell *shell)
{
	t_tlist	*first;
	t_tlist	*tokens;
	t_clist	*commands;

	first = ft_lexer(shell, shell->input, shell->input_len, GENERAL_STATE);
	if (!first->type)
		return (NULL);
	tokens = first;
	commands = NULL;
	while (tokens)
	{
		tokens = tokens->next;
	}
	ft_free_tlist(first);
	return (commands);
}
