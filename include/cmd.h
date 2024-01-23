/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:34:15 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/23 16:01:28 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "minishell.h"

typedef struct s_list_node
{
	char				*s_node;
	int					type_node;
	struct s_list_node	*next;
}				t_list_node;

typedef struct s_redir
{
	int				type; // "OUTPUT" "APPEND" "INPUT" "HEREDOC" "PRIOROUTPUT"
	char			*str; // "1" "2" "3" "4" "5" "c"
	struct s_redir	*next;
}			t_redir;


typedef struct s_cmd
{
	int			is_first;

	int				id;
//	char			**cmd_splitted; // "ls" "-l"
	char			*cmd_str; // "ls -l"

	int				in; //fd in cmd
	int				out; //fd in cmd

	t_redir			*redirs;

	struct s_cmd	*next;
}					t_cmd;

t_cmd	*ft_lstnew_cmd(char *s);
int		ft_lstsize_cmd(t_cmd *lst);
t_cmd	*ft_lstlast_cmd(t_cmd *head);
void	ft_lstadd_front_cmd(t_cmd **l, t_cmd *new_head);
void	ft_lstadd_back_cmd(t_cmd **l, t_cmd *new);



t_redir	*ft_lstlast_red(t_redir *head);

void	ft_lstadd_back_redir(t_redir **l, t_redir *new);
t_redir	*ft_lstnew_redir(char *s, int t);

#endif
