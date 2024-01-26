/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:16:03 by filippo           #+#    #+#             */
/*   Updated: 2024/01/26 12:30:08 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_simple_command(t_tlist **token, t_clist *cmd)
{
	char	**args;

	args = ft_args(token);
	if (!args)
		return ;
	cmd->args = args;
}

static void	ft_command(t_tlist **token, t_clist *cmd)
{
	ft_io_lists(token, cmd);
	ft_simple_command(token, cmd);
	ft_io_lists(token, cmd);
}

static t_clist	*ft_jobs(t_tlist **token);

static t_clist	*ft_job(t_tlist **token)
{
	t_clist	*cmd;
	t_tlist	*save;
	t_clist	*job;

	cmd = ft_new_clnode();
	ft_command(token, cmd);
	save = *token;
	if (!ft_term(token, PIPE_TOKEN, NULL))
	{
		*token = save;
		if (!ft_term(token, LF_TOKEN, NULL))
			return (ft_free_clist(cmd));
	}
	job = ft_jobs(token);
	if (!job)
		return (ft_free_clist(cmd));
	cmd->next = job;
	return (cmd);
}

static t_clist	*ft_jobs(t_tlist **token)
{
	t_tlist	*save;
	t_clist	*output;

	save = *token;
	output = ft_job(token);
	if (output)
		return (output);
	*token = save;
	output = ft_new_clnode();
	ft_command(token, output);
	return (output);
}

t_clist	*ft_parser(t_shell *shell)
{
	t_tlist	*first;
	t_tlist	*last;
	t_clist	*commands;

	first = ft_lexer(shell, shell->input, shell->input_len, GENERAL_STATE);
	if (!first->type)
		return (NULL);
	commands = NULL;
	last = first;
	if (!ft_check_grammar(&last))
		printf(SYNTAX_ERROR "`%s`\n", last->data);
	else
	{
		last = first;
		commands = ft_jobs(&last);
	}
	ft_free_tlist(first);
	return (commands);
}
