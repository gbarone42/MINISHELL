/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:02:04 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/23 14:37:45 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_io_list_4(t_tlist **token, t_clist *cmd)
{
	char	*input_filename;

	if (!ft_term(token, LESSER_TOKEN, NULL))
		return (0);
	if (!ft_term(token, GENERAL_TOKEN, &input_filename))
		return (0);
	ft_app_rlist(&cmd->redirections, INPUT, input_filename);
	ft_io_lists(token, cmd);
	return (1);
}

static int	ft_io_list_3(t_tlist **token, t_clist *cmd)
{
	char	*output_filename;

	if (!ft_term(token, GREATER_TOKEN, NULL))
		return (0);
	if (!ft_term(token, GENERAL_TOKEN, &output_filename))
		return (0);
	ft_app_rlist(&cmd->redirections, OUTPUT, output_filename);
	ft_io_lists(token, cmd);
	return (1);
}

static int	ft_io_list_2(t_tlist **token, t_clist *cmd)
{
	char	*heredoc_filename;

	if (!ft_term(token, DLESSER_TOKEN, NULL))
		return (0);
	if (!ft_term(token, GENERAL_TOKEN, &heredoc_filename))
		return (0);
	ft_app_rlist(&cmd->redirections, HEREDOC, heredoc_filename);
	ft_io_lists(token, cmd);
	return (1);
}

static int	ft_io_list_1(t_tlist **token, t_clist *cmd)
{
	char	*append_filename;

	if (!ft_term(token, DGREATER_TOKEN, NULL))
		return (0);
	if (!ft_term(token, GENERAL_TOKEN, &append_filename))
		return (0);
	ft_app_rlist(&cmd->redirections, APPEND, append_filename);
	ft_io_lists(token, cmd);
	return (1);
}

void	ft_io_lists(t_tlist **token, t_clist *cmd)
{
	t_tlist	*save;

	save = *token;
	if (ft_io_list_1(token, cmd))
		return ;
	*token = save;
	if (ft_io_list_2(token, cmd))
		return ;
	*token = save;
	if (ft_io_list_3(token, cmd))
		return ;
	*token = save;
	if (ft_io_list_4(token, cmd))
		return ;
	*token = save;
}
