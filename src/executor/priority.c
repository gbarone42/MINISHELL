/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/25 17:37:36 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	excve_core_prio(t_shell *ms, char *paths, char **cmd)
{
	if (access(paths, F_OK | X_OK) == 0)
	{
		execve(paths, cmd, ms->env_list);
		perror("execve");
	}
}

void	ft_child_prio(t_shell *ms, t_clist *cmd, int inf, int outf)
{
	char	**cmd_sp;
	char	*paths;
	int		i;

	i = 0;
	dup2(inf, STDIN_FILENO);
	dup2(outf, STDOUT_FILENO);
	dup2(outf, STDERR_FILENO);
	cmd_sp = cmd->args;
	if (strcmp(cmd_sp[0], ""))
	{
		execve("/dev/null", cmd_sp, ms->env_list);
		ft_free_shell(ms);
		exit(1);
	}
	excve_core_prio(ms, cmd_sp[0], cmd_sp);
	while (ms->paths[i])
	{
		paths = ft_strjoin(ms->paths[i], cmd_sp[0]);
		excve_core_prio(ms, paths, cmd_sp);
		free(paths);
		i++;
	}
	ft_free_shell(ms);
	exit(1);
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

int	ft_isprio_cmd(t_shell *ms, t_clist *cmd)
{
	int	pid1;
	int	inf;
	int	outf;

	inf = open("/dev/null", O_RDONLY);
	outf = open(".tmp_n", O_TRUNC | O_CREAT | O_RDWR, 0644);
	pid1 = fork();
	if (pid1 == 0)
		ft_child_prio(ms, cmd, inf, outf);
	close(inf);
	close(outf);
	waitpid(pid1, NULL, 0);
	inf = open("/etc/passwd", O_RDONLY);
	outf = open(".tmp_f", O_TRUNC | O_CREAT | O_RDWR, 0644);
	pid1 = fork();
	if (pid1 == 0)
		ft_child_prio(ms, cmd, inf, outf);
	close(inf);
	close(outf);
	waitpid(pid1, NULL, 0);
	return (ft_compare_file(".tmp_n", ".tmp_f"));
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
				||	ft_isprio_cmd(ms, iter) != 0) && !isfirst)
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
