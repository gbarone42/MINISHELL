/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:31:23 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/12/06 13:32:22 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
	Function from libft updated
*/

/*
	Libft Create New Node adapted for t_list of push_swap
*/
t_cmd	*ft_lstnew(char *s)
{
	t_cmd	*n;

	n = (t_cmd *) malloc(sizeof(*n));
	if (!n)
		return (NULL);
	n->next = NULL;
	n->cmd_str = s;
	return (n);
}

/*
	Libft Add Back adapted for t_list of push_swap
*/
void	ft_lstadd_back(t_cmd **l, t_cmd *new)
{
	t_cmd	*last;

	if (*l)
	{
		last = ft_lstlast(*l);
		last->next = new;
		new->next = NULL;
	}
	else
	{
		*l = new;
		(*l)->next = NULL;
	}
}

/*
	Libft List Add front adapted for t_list of push_swap
*/
void	ft_lstadd_front(t_cmd **l, t_cmd *new_head)
{
	new_head->next = *l;
	*l = new_head;
}

/*
	Libft List last adapted for t_list of push_swap
*/
t_cmd	*ft_lstlast(t_cmd *head)
{
	t_cmd	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

/*
	Libft List Size adapted for t_list of push_swap
*/
int	ft_lstsize(t_cmd *lst)
{
	t_cmd		*next_lst;
	int				out;

	next_lst = lst;
	out = 0;
	while (next_lst != NULL)
	{
		out++;
		next_lst = next_lst->next;
	}
	return (out);
}
