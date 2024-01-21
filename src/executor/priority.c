/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/21 20:31:12 by sdel-gra         ###   ########.fr       */
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
	dup2(inf, STDIN_FILENO);
	dup2(outf, STDOUT_FILENO);
	//dup2(outf, 2);
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
		printf("f1:%s\n",f_line[0]);
		printf("f2:%s\n",f_line[1]);
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

int	ft_isprio_cmd(t_mshell *ms, t_cmd *cmd)
{
	int	pid1;
	int	inf;
	int	outf;

	inf = open("/dev/null", O_RDONLY);
	outf =  open(".tmp_n", O_TRUNC | O_CREAT | O_RDWR, 0644);
	pid1 = fork();
	if (pid1 == 0)
		ft_child_prio(ms, cmd, inf, outf);
	close(inf);
	close(outf);
	waitpid(pid1, NULL, 0);
	inf = open("/etc/passwd", O_RDONLY);
	outf =  open(".tmp_f", O_TRUNC | O_CREAT | O_RDWR, 0644);
	pid1 = fork();
	if (pid1 == 0)
		ft_child_prio(ms, cmd, inf, outf);
	close(inf);
	close(outf);
	waitpid(pid1, NULL, 0);
	return (ft_compare_file(".tmp_n", ".tmp_f"));
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
	int		isfirst;

	isfirst = 1;
	iter = *cmds;
	tmp_prev = NULL;
	while (iter)
	{
		if (ft_isprio_cmd(ms, iter) == 0 && !isfirst)
		{
			if (!ft_redir_out_exist(iter->redirs) || iter->next)
				ft_lstadd_back_redir(&iter->redirs, ft_lstnew_redir("", PRIOROUTPUT));
			/* muovi il comando all'inizio*/
			tmp_prev->next = NULL;
			tmp_prev = ft_lstlast(iter);
			tmp_prev ->next = ms->c_l;
			ms->c_l = iter;
			break ;
		}
		tmp_prev = iter;
		iter = iter->next;
		isfirst = 0;
	}
}
