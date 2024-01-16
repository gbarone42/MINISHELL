#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_list_node
{
	char				*s_node;
	int					type_node;
	struct s_list_node	*next;
}				t_list_node;


void ft_prio_cmd(t_mshell *ms, t_cmd **cmds);

void	ft_exec(t_mshell *ms, char *envp[]);

void	ft_redir(t_mshell *ms, t_cmd *cmd);

void    close_fd(int fd);

void	path_finder(t_mshell *px, char **envp);

t_cmd	*ft_lstnew(char *s);
int		ft_lstsize(t_cmd *lst);
t_cmd	*ft_lstlast(t_cmd *head);
void	ft_lstadd_front(t_cmd **l, t_cmd *new_head);
void	ft_lstadd_back(t_cmd **l, t_cmd *new);

char	*ft_free_char(char **ptr);
void	ft_free_tutto(t_mshell *px, char ***cmd, char **cmd_path);

void	ft_lstclear_redir(t_redir **lst);
void	ft_lstclear(t_cmd **lst);

#endif
