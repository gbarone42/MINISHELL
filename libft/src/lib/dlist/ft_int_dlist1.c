/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dlist1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:33:38 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/01 17:13:33 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int_dlist	*ft_int_dlst_new(int content)
{
	t_int_dlist	*output;

	output = malloc(sizeof(t_int_dlist));
	if (!output)
		return (NULL);
	output->content = content;
	output->next = NULL;
	output->prev = NULL;
	return (output);
}

void	ft_int_dlst_add_back(t_int_dlist **lst, t_int_dlist *new)
{
	t_int_dlist	*node;

	if (!lst)
		ft_error("FT_INT_DLST_ADD_BACK", "PARAMETER LST is NULL");
	if (!new)
		ft_error("FT_INT_DLST_ADD_BACK", "PARAMETER NEW is NULL");
	node = *lst;
	if (!node)
		node = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node;
	}
	*lst = new;
}

void	ft_int_dlst_add_front(t_int_dlist **lst, t_int_dlist *new)
{
	t_int_dlist	*node;

	if (!lst)
		ft_error("FT_INT_DLST_ADD_FRONT", "PARAMETER LST is NULL");
	if (!new)
		ft_error("FT_INT_DLST_ADD_BACK", "PARAMETER NEW is NULL");
	node = *lst;
	if (node)
	{
		new->next = node;
		new->prev = node->prev;
		if (node->prev)
			node->prev->next = new;
		node->prev = new;
	}
	*lst = new;
}

void	ft_int_dlst_clear(t_int_dlist **lst)
{
	t_int_dlist	*tmp;
	t_int_dlist	*node;

	if (!lst)
		ft_error("FT_INT_DLST_CLEAR", "PARAMETER LST is NULL");
	node = *lst;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*lst = NULL;
}

void	ft_int_dlst_del_one(t_int_dlist **lst)
{
	t_int_dlist	*node;
	t_int_dlist	*prev;
	t_int_dlist	*next;

	if (!lst)
		ft_error("FT_INT_DLST_DEL_ONE", "PARAMETER LST is NULL");
	node = *lst;
	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	free(node);
	*lst = next;
}
