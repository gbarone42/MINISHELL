/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:34:07 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/24 13:58:00 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

typedef struct command_node	t_clist;
typedef struct s_shell		t_shell;
typedef struct redirection	t_rlist;

void	ft_exec_cmd(t_shell *ms);

void	ft_prio_cmd(t_shell *ms, t_clist **cmds);

void	ft_exec(t_shell *ms);

void	ft_rlist(t_shell *ms, t_clist *cmd);

void	close_fd(int fd);

void	path_finder(t_shell *px, char **envp);

t_clist	*ft_lstnew_cmd(char *s);
int		ft_lstsize_cmd(t_clist *lst);
t_clist	*ft_last_clist(t_clist *head);
void	ft_lstadd_front_clist(t_clist **l, t_clist *new_head);
void	ft_lstadd_back_cmd(t_clist **l, t_clist *new);

char	*ft_free_char(char **ptr);
void	ft_free_tutto(t_shell *px, char ***cmd, char **cmd_path);

void	ft_lstclear_redir(t_rlist **lst);
void	ft_lstclear_cmd(t_clist **lst);

#endif
