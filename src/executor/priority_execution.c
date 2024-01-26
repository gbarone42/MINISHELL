/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:40:11 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/26 14:45:04 by sdel-gra         ###   ########.fr       */
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
