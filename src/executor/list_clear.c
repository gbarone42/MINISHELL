#include "../includes/minishell.h"

void	ft_lstdelone_redir(t_redir *lst)
{
	if (lst != NULL)
	{
		lst->str = ft_free(&lst->str);
		free(lst);
		lst = NULL;
	}
}

void	ft_lstclear_redir(t_redir **lst)
{
	if (lst != NULL && *lst != NULL)
	{
		ft_lstclear_redir(&(*lst)->next);
		ft_lstdelone_redir(*lst);
		*lst = NULL;
	}
}

void	ft_lstdelone(t_cmd *lst)
{
	if (lst != NULL)
	{
		lst->cmd_str = ft_free(&(lst->cmd_str));
		ft_lstclear_redir(&lst->redirs);
		lst->redirs = NULL;
		free(lst);
		lst = NULL;
	}
}

void	ft_lstclear(t_cmd **lst)
{
	if (lst != NULL && *lst != NULL)
	{
		ft_lstclear(&(*lst)->next);
		ft_lstdelone(*lst);
		*lst = NULL;
	}
}
