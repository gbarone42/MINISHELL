/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:40:59 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/23 16:03:28 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	ft_lstdelone_cmd(t_cmd *lst)
{
	if (lst != NULL)
	{
		if (lst->cmd_str)
		{
			free(lst->cmd_str);
			lst->cmd_str = NULL;
		}
		ft_lstclear_redir(&lst->redirs);
		lst->redirs = NULL;
		free(lst);
		lst = NULL;
	}
}

void	ft_lstclear_cmd(t_cmd **lst)
{
	if (lst != NULL && *lst != NULL)
	{
		ft_lstclear_cmd(&(*lst)->next);
		ft_lstdelone_cmd(*lst);
		*lst = NULL;
	}
}
