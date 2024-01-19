/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_base_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:41:05 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/19 16:41:13 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redir	*ft_lstlast_red(t_redir *head)
{
	t_redir	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lstadd_back_redir(t_redir **l, t_redir *new)
{
	t_redir	*last;

	if (*l)
	{
		last = ft_lstlast_red(*l);
		last->next = new;
		new->next = NULL;
	}
	else
	{
		*l = new;
		(*l)->next = NULL;
	}
}

t_redir	*ft_lstnew_redir(char *s, int t)
{
	t_redir	*n;

	n = (t_redir *) malloc(sizeof(*n));
	if (!n)
		return (NULL);
	n->next = NULL;
	n->str = s;
	n->type = t;
	return (n);
}
