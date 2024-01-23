/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:34:07 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/23 16:01:10 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

typedef struct s_cmd	t_cmd;

typedef struct s_mshell
{
	pid_t		pid_child;
	int			fd_pipe[2];
	int			tmp_fd;
	int			outfile;
	int			infile;
	char		**env;
	char		**cmd_path;
	char		*cmd_args;
	int			exit_stat;
	t_cmd		*c_l;
}				t_mshell;

void	ft_prio_cmd(t_mshell *ms, t_cmd **cmds);

void	ft_exec(t_mshell *ms, char *envp[]);

void	ft_redir(t_mshell *ms, t_cmd *cmd);

void	close_fd(int fd);

void	path_finder(t_mshell *px, char **envp);

t_cmd	*ft_lstnew_cmd(char *s);
int		ft_lstsize_cmd(t_cmd *lst);
t_cmd	*ft_lstlast_cmd(t_cmd *head);
void	ft_lstadd_front_cmd(t_cmd **l, t_cmd *new_head);
void	ft_lstadd_back_cmd(t_cmd **l, t_cmd *new);

char	*ft_free_char(char **ptr);
void	ft_free_tutto(t_mshell *px, char ***cmd, char **cmd_path);

void	ft_lstclear_redir(t_redir **lst);
void	ft_lstclear_cmd(t_cmd **lst);

#endif
