/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/02/02 18:21:45 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redir_out_exist(t_rlist *redirs)
{
	t_rlist	*tmp;

	tmp = redirs;
	while (tmp)
	{
		if (tmp->type == APPEND || tmp->type == OUTPUT)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_catchange(t_clist *cmds)
{
	t_clist	*iter;

	iter = cmds;
	while (iter && iter->args)
	{
		if (ft_strcmp(cmds->args[0], "cat") == 0)
		{
			cmds->args[0] = ft_free(&cmds->args[0]);
			cmds->args[0] = ft_strdup("readbuiltin");
		}
		if (!ft_redir_out_exist(iter->redirections))
			ft_app_rlist(&iter->redirections, DEVNULLOUT, ft_strdup(""));
		iter = iter -> next;
	}
}

int	ft_isprio_cmd2(t_clist *cmds)
{
	char	*builtins[5];
	size_t	i;

	i = 0;
	if (cmds && cmds->args)
	{
		builtins[0] = "mkdir";
		builtins[1] = "rmdir";
		builtins[2] = "touch";
		builtins[3] = "rm";
		builtins[4] = NULL;
		while (builtins[i] != NULL)
			if (ft_strcmp(cmds->args[0], builtins[i++]) == 0)
				return (1);
	}
	return (0);
}

static void	ft_handle_next_prev(t_clist *iter, t_clist **tmp_prev, t_shell *ms)
{
	if (!ft_redir_out_exist(iter->redirections) || !iter->next)
		ft_app_rlist(&iter->redirections, PRIOROUTPUT, ft_strdup(""));
	(*tmp_prev)->next = NULL;
	*tmp_prev = ft_last_clist(iter);
	(*tmp_prev)->next = ms->commands;
	ft_catchange((*tmp_prev)->next);
	ms->commands = iter;
}

void	ft_prio_cmd(t_shell *ms, t_clist **cmds)
{
	t_clist	*iter;
	t_clist	*tmp_prev;
	int		isfirst;

	isfirst = 1;
	iter = *cmds;
	tmp_prev = NULL;
	while (iter)
	{
		if ((is_builtin_command(iter->args[0]) || ft_isprio_cmd(ms, iter) == 0
				|| ft_isprio_cmd2(iter)))
		{
			if (!isfirst)
				ft_handle_next_prev(iter, &tmp_prev, ms);
			break ;
		}
		tmp_prev = iter;
		iter = iter->next;
		isfirst = 0;
	}
}
