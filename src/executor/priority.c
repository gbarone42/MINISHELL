/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/19 16:50:30 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	excve_core_prio(t_mshell *ms, char *cmd_path, char **cmd)
{
	if (access(cmd_path, F_OK | X_OK) == 0)
	{
		execve(cmd_path, cmd, ms->env);
		perror("execve");
		//free CMDSP
		//FREE MS
		//FREE PATH(?)
	}
}

void	ft_child_prio(t_mshell *ms, t_cmd *cmd, int inf, int outf)
{
	char	**cmd_sp;
	char	*cmd_path;
	int		i;

	i = 0;
	dup2(inf, 0);
	dup2(outf, 1);
	dup2(outf, 2);
	cmd_sp = ft_split(cmd->cmd_str, ' ');
	excve_core_prio(ms, cmd_sp[0], cmd_sp);
	while (ms->cmd_path[i])
	{
		cmd_path = ft_strjoin(ms->cmd_path[i], cmd_sp[0]);
		excve_core_prio(ms, cmd_path, cmd_sp);
		free(cmd_path);
		i++;
	}
	//free ms
	//FREE CMD_SP
}

int	ft_compare_file(char *filename1, char *filename2)
{
	char	*f_line[2];
	int		fd[2];
	int		out;

	out = 1;
	fd[0] = open(filename1, O_RDONLY);
	fd[1] = open(filename2, O_RDONLY);
	f_line[0] = get_next_line(fd[0]);
	f_line[1] = get_next_line(fd[1]);
	while (f_line[0] != NULL || f_line[1] != NULL)
	{
		if (!strcmp(f_line[0], f_line[1]) == 0)
			out = 0;
		f_line[0] = ft_free(f_line + 0);
		f_line[1] = ft_free(f_line + 1);
		f_line[0] = get_next_line(fd[0]);
		f_line[1] = get_next_line(fd[1]);
	}
	if (!strcmp(f_line[0], f_line[1]) == 0)
		out = 0;
	close_fd(fd[0]);
	close_fd(fd[1]);
	return (out);
}

int	ft_isprio_cmd(t_mshell *ms, t_cmd *cmd)
{
	int	pid1;
	int	inf;
	int	outf;

	inf = open("/dev/null", O_RDONLY);
	outf =  open(".tmp_testnull", O_TRUNC | O_CREAT | O_RDWR, 0644);
	pid1 = fork();
	if (pid1 == 0)
		ft_child_prio(ms, cmd, inf, outf);
	waitpid(pid1, NULL, 0);
	close(inf);
	close(outf);
	inf = open("/etc/passwd", O_RDONLY);
	outf =  open(".tmp_testfull", O_TRUNC | O_CREAT | O_RDWR, 0644);
	pid1 = fork();
	if (pid1 == 0)
		ft_child_prio(ms, cmd, inf, outf);
	waitpid(pid1, NULL, 0);
	close(inf);
	close(outf);
	return (ft_compare_file(".tmp_testnull", ".tmp_testfull"));
}

int	ft_redir_out_exist(t_redir *redirs)
{
	t_redir	*tmp;

	tmp = redirs;
	while (tmp)
	{
		if (tmp->type == APPEND || tmp->type == OUTPUT)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void ft_prio_cmd(t_mshell *ms, t_cmd **cmds)
{
	t_cmd	*iter;
	t_cmd	*tmp_prev;

	iter = *cmds;
	tmp_prev = NULL;
	while (iter)
	{
		if (ft_isprio_cmd(ms, iter))
		{
			if (!ft_redir_out_exist(iter->redirs) || iter->next)
				ft_lstadd_back_redir(&iter->redirs, ft_lstnew_redir("", PRIOROUTPUT));
			/* muovi il comando all'inizio*/
			if (tmp_prev)
			{
				/* code */
			}
		}
		tmp_prev = iter;
		iter = iter->next;
	}
}
