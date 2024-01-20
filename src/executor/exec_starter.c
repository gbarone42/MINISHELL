/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/20 19:43:08 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	path_finder(t_mshell *px, char **envp)
{
	char	**tmp;
	char	*tofree;
	int		i;

	i = 0;
	tmp = envp;
	while (tmp && ft_strncmp("PATH=", *tmp, 5))
		tmp++;
	px->cmd_path = ft_split((*tmp) + 5, ':');
	while (px->cmd_path[i])
	{
		tofree = px->cmd_path[i];
		px->cmd_path[i] = ft_strjoin(px->cmd_path[i], "/");
		ft_free_char(&tofree);
		i++;
	}
}

void	ft_exec_cmd(t_mshell *ms, char *envp[])
{
	pipe(ms->fd_pipe);
	ft_exec(ms, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_mshell	ms;
	int			i;
	t_cmd		*tmpcmd;
	char *str = "PATH=/home/simo/.local/bin:/home/simo/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files/WindowsApps/MicrosoftCorporationII.WindowsSubsystemForLinux_1.2.5.0_x64__8wekyb3d8bbwe:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/Program Files/Microsoft/jdk-11.0.12.7-hotspot/bin:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/Microsoft SQL Server/150/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/Client SDK/ODBC/170/Tools/Binn/:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files (x86)/Microsoft SQL Server/150/DTS/Binn/:/mnt/c/Program Files (x86)/Microsoft SQL Server/160/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/160/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/160/DTS/Binn/:/mnt/c/Program Files (x86)/Microsoft SQL Server/160/DTS/Binn/:/mnt/c/Program Files/Docker/Docker/resources/bin:/mnt/c/Program Files/MySQL/MySQL Shell 8.0/bin/:/mnt/c/Users/S/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/S/.dotnet/tools:/mnt/c/Users/S/AppData/Local/GitHubDesktop/bin:/mnt/c/Program Files/Azure Data Studio/bin:/mnt/c/Users/S/AppData/Local/Programs/Microsoft VS Code/bin:/snap/bin";

	i = 0;
	ms.c_l = NULL;
	ms.infile = STDIN_FILENO;
	ms.outfile = STDOUT_FILENO;
	ms.env = &str;
	ms.tmp_fd = -1 ;
	while (i < argc - 1)
	{
		tmpcmd = ft_lstnew(argv[i + 1]);
		//tmpcmd->redirs = ft_lstnew_redir("12", APPEND);
		tmpcmd->in = -2;
		tmpcmd->out = -2;
		if(i == 0)
		{
			tmpcmd->is_first = 1;
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("1", INPUT));
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("11", OUTPUT));
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("2", INPUT));
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("13", OUTPUT));
		}
		else
			tmpcmd->is_first = 0;
		ft_lstadd_back(&(ms.c_l), tmpcmd);
		tmpcmd = NULL;
		i++;
	}
	path_finder(&ms, envp);
	ft_prio_cmd(&ms, &ms.c_l);
	i = 0;
	tmpcmd = ms.c_l;
	while (tmpcmd)
	{
		printf("%s\n", tmpcmd->cmd_str);
		tmpcmd = tmpcmd ->next;
	}
	ms.env = envp;

	//envp = NULL;
/*
	while (ms.c_l)
	{
		printf("%s\n", ms.c_l->cmd_str);
		ms.c_l=ms.c_l->next;
	}*/

	//ft_exec_cmd(&ms, envp);
	//ft_lstclear(&ms.c_l);
}
/*
void	command_handler(t_mshell *px, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd = ft_split(px->c_l->cmd, ' ');
	while (px->cmd_path[i])
	{
		cmd_path = ft_strjoin(px->cmd_path[i], cmd[0]);
		if (access(cmd_path, F_OK | X_OK) == 0)
			break ;
		else
			ft_free_char(&cmd_path);
		i++;
	}
	if (!cmd_path)
		ft_free_tutto(px, &cmd, &cmd_path);
	if (execve(cmd_path, cmd, envp) == -1)
		write(1, "errore execve\n", 14);
}


void	child_handler(t_mshell *ms, char *envp[], int fd_in)
{
	printf("\e[1;31mChild (PID: %d) executed cmd:\e[0m\n", getpid());
	if (1)//se ci sono redirection entra qua
		ft_redir(ms, fd_in);

	if (ms->c_l->next)
    	dup2(ms->fd_pipe[1], 1);
	else
		dup2(ms->c_l->out, 1);
	close(ms->fd_pipe[0]);
	command_handler(ms, envp);

}

void	ft_exec(t_mshell *ms, char *envp[])
{
	pid_t	child_pid;
	int		i;
	int		fd_in;

	fd_in = 0;
	i = 0;
	path_finder(ms, envp);
	while (ms->c_l)
	{
		pipe(ms->fd_pipe);
		child_pid = fork();
		if (child_pid == 0)
		{
			child_handler(ms, envp, fd_in);
		}
		else
		{
			close(ms->fd_pipe[1]);
			fd_in = ms->fd_pipe[0];
			waitpid(child_pid, 0, 0);
		}
		ms->c_l = ms->c_l->next;
		i++;
	}
}*/

