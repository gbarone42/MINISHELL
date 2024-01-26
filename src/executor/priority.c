/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 20:11:41 by sdel-gra         ###   ########.fr       */
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

/*
void	ft_catchange(t_clist *cmds, char *cmd_name)
{
	t_clist	*iter;

	iter = cmds;
	while (iter && iter->cmd_str)
	{
		iter = iter -> next;
	}
}*/

void	ft_prio_cmd(t_shell *ms, t_clist **cmds)
{
	t_clist	*iter;
	t_clist	*tmp_prev;
	int		isfirst;
	int o1, o2;

	isfirst = 1;
	iter = *cmds;
	tmp_prev = NULL;
	while (iter)
	{
		o1 =is_builtin_command(iter->args[0]);
		o2 = ft_isprio_cmd(ms, iter);
		if ((o1|| o2 == 0) && !isfirst)
		{
			//ft_catchange();
			if (!ft_redir_out_exist(iter->redirections) || !iter->next)
				ft_app_rlist(&iter->redirections, PRIOROUTPUT, "");
			tmp_prev->next = NULL;
			tmp_prev = ft_last_clist(iter);
			tmp_prev ->next = ms->commands;
			ms->commands = iter;
			break ;
		}
		tmp_prev = iter;
		iter = iter->next;
		isfirst = 0;
	}
}
