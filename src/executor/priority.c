/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 14:41:55 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_compare_file(char *filename1, char *filename2)
{
	char	*f_line[2];
	int		fd1;
	int		fd2;
	int		out;

	out = 0;
	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	f_line[0] = get_next_line(fd1);
	f_line[1] = get_next_line(fd2);
	while (f_line[0] != NULL || f_line[1] != NULL)
	{
		out = ft_strcmp(f_line[0], f_line[1]);
		f_line[0] = ft_free(f_line + 0);
		f_line[1] = ft_free(f_line + 1);
		if (out != 0)
			break ;
		f_line[0] = get_next_line(fd1);
		f_line[1] = get_next_line(fd2);
	}
	close(fd1);
	close(fd2);
	get_next_line(fd1);
	get_next_line(fd2);
	return (out);
}

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

	isfirst = 1;
	iter = *cmds;
	tmp_prev = NULL;
	while (iter)
	{
		if ((is_builtin_command(iter->args[0])
				|| ft_isprio_cmd(ms, iter) != 0) && !isfirst)
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
