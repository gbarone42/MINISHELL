/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_starter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/25 12:20:48 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main_1(int argc, char **argv, char **env);

int	is_builtin_command(char *command)
{
	const char	*builtins[12];
	size_t		i;

	i = 0;
	if (command)
	{
		builtins[0] = "echo";
		builtins[1] = "cd";
		builtins[2] = "pwd";
		builtins[3] = "export";
		builtins[4] = "unset";
		builtins[5] = "env";
		builtins[6] = "exit";
		builtins[7] = "rm";
		builtins[8] = "mkdir";
		builtins[9] = "rmdir";
		builtins[10] = NULL;
		builtins[11] = NULL;
		while (builtins[i] != NULL)
			if (strcmp(command, builtins[i++]) == 0)
				return (1);
	}
	return (0);
}

void	path_finder(t_shell *px)
{
	char	**tmp;
	char	*tofree;
	int		i;

	i = 0;
	tmp = px->env_list;
	if (px->paths)
	{
		ft_free_char_p(px->paths);
		px->paths = NULL;
	}
	while (tmp && ft_strncmp("PATH=", *tmp, 5))
		tmp++;
	px->paths = ft_split((*tmp) + 5, ':');
	while (px->paths[i])
	{
		tofree = px->paths[i];
		px->paths[i] = ft_strjoin(px->paths[i], "/");
		ft_free_char(&tofree);
		i++;
	}
}

void	ft_exec_cmd(t_shell *ms)
{
	path_finder(ms);
	//ft_prio_cmd(ms, &ms->commands);
	//builtins_call(ms, ms->commands);
	pipe(ms->fd_pipe);
	ft_exec(ms);
}
/*
int	main_2(int argc, char *argv[], char *envp[])
{
	t_shell	ms;
	int			i;
	t_clist		*tmpcmd;
	char *str = "PATH=/home/simo/.local/bin:/home/simo/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files/WindowsApps/MicrosoftCorporationII.WindowsSubsystemForLinux_1.2.5.0_x64__8wekyb3d8bbwe:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/Program Files/Microsoft/jdk-11.0.12.7-hotspot/bin:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files/Microsoft SQL Server/150/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/Client SDK/ODBC/170/Tools/Binn/:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files (x86)/Microsoft SQL Server/150/DTS/Binn/:/mnt/c/Program Files (x86)/Microsoft SQL Server/160/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/160/Tools/Binn/:/mnt/c/Program Files/Microsoft SQL Server/160/DTS/Binn/:/mnt/c/Program Files (x86)/Microsoft SQL Server/160/DTS/Binn/:/mnt/c/Program Files/Docker/Docker/resources/bin:/mnt/c/Program Files/MySQL/MySQL Shell 8.0/bin/:/mnt/c/Users/S/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/S/.dotnet/tools:/mnt/c/Users/S/AppData/Local/GitHubDesktop/bin:/mnt/c/Program Files/Azure Data Studio/bin:/mnt/c/Users/S/AppData/Local/Programs/Microsoft VS Code/bin:/snap/bin";

	i = 0;
	ms.commands = NULL;
	ms.infile = STDIN_FILENO;
	ms.outfile = STDOUT_FILENO;
	ms.env = &str;
	ms.tmp_fd = -1 ;
	while (i < argc - 1)
	{
		tmpcmd = ft_lstnew_cmd(argv[i + 1]);
		//tmpcmd->redirs = ft_lstnew_redir("12", APPEND);
		tmpcmd->in = -2;
		tmpcmd->out = -2;
		tmpcmd->redirs = ft_lstnew_redir(NULL, ND);
		if(i == 0)
		{
			//tmpcmd->is_first = 1;
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("1", INPUT));
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("11", HEREDOC));
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("2", INPUT));
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("13", OUTPUT));
		}
		if (i == 1)
		{
			//ft_lstadd_back_redir(&tmpcmd->redirs , ft_lstnew_redir("11", HEREDOC));
		}
		
		else
			tmpcmd->is_first = 0;
		ft_lstadd_back_cmd(&(ms.commands), tmpcmd);
		tmpcmd = NULL;
		i++;
	}
//	path_finder(&ms, envp);
//	ft_prio_cmd(&ms, &ms.commands);
	i = 0;
	tmpcmd = ms.commands;
	while (tmpcmd)
	{
		printf("%s\n", tmpcmd->cmd_str);
		tmpcmd = tmpcmd ->next;
	}
	ms.commands->is_first = 1;
	//ms.env = envp;

	//envp = NULL;


//	ft_exec_cmd(&ms, envp);

	//main_1(argc, argv, envp);
	//ft_lstclear(&ms.commands);
	return (1);
}*/
/*
void	command_handler(t_shell *px, char **envp)
{
	char	**cmd;
	char	*paths;
	int		i;

	i = 0;
	cmd = ft_split(px->commands->cmd, ' ');
	while (px->paths[i])
	{
		paths = ft_strjoin(px->paths[i], cmd[0]);
		if (access(paths, F_OK | X_OK) == 0)
			break ;
		else
			ft_free_char(&paths);
		i++;
	}
	if (!paths)
		ft_free_tutto(px, &cmd, &paths);
	if (execve(paths, cmd, envp) == -1)
		write(1, "errore execve\n", 14);
}


void	child_handler(t_shell *ms, char *envp[], int fd_in)
{
	printf("\e[1;31mChild (PID: %d) executed cmd:\e[0m\n", getpid());
	if (1)//se ci sono redirection entra qua
		ft_redir(ms, fd_in);

	if (ms->commands->next)
    	dup2(ms->fd_pipe[1], 1);
	else
		dup2(ms->commands->out, 1);
	close(ms->fd_pipe[0]);
	command_handler(ms, envp);

}

void	ft_exec(t_shell *ms, char *envp[])
{
	pid_t	child_pid;
	int		i;
	int		fd_in;

	fd_in = 0;
	i = 0;
	path_finder(ms, envp);
	while (ms->commands)
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
		ms->commands = ms->commands->next;
		i++;
	}
}*/

