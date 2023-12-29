/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:16:03 by filippo           #+#    #+#             */
/*   Updated: 2023/12/29 12:10:14 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	<command line>		::=		<job>

	<job>				::=		<command>
							|	<job> '|' <command>

	<command>			::=		<simple command>
							|	<command> '<' <filename>
							|	<command> '>' <filename>

	<simple command>	::=		<pathname> <token list>

	<token list>		::=		<token> <token list>
							|	EMPTY
 */

#include "minishell_p.h"

void	ft_parser(t_shell *shell)
{
	t_tlist	*token;

	token = ft_lexer(shell, shell->input, shell->input_len, GENERAL_STATE);
}
