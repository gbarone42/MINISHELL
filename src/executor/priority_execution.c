/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:40:11 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 20:11:14 by sdel-gra         ###   ########.fr       */
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
	close_fd(fd1);
	close_fd(fd2);
	get_next_line(fd1);
	get_next_line(fd2);
	return (out);
}

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
	cmd_sp = cmd->args;
	if (ft_strcmp(cmd_sp[0], "") == 0)
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
	close_fd(inf);
	close_fd(outf);
	waitpid(pid1, NULL, 0);
	inf = open("/etc/passwd", O_RDONLY);
	outf = open(".tmp_f", O_TRUNC | O_CREAT | O_RDWR, 0644);
	pid1 = fork();
	if (pid1 == 0)
		ft_child_prio(ms, cmd, inf, outf);
	close_fd(inf);
	close_fd(outf);
	waitpid(pid1, NULL, 0);
	return (ft_compare_file(".tmp_n", ".tmp_f"));
}
