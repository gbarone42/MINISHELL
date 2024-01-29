/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dlist2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:20:47 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/21 19:35:39 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_dlst_iter(t_int_dlist *lst, void (*f)(int *))
{
	if (!lst)
		ft_error("ft_int_dlst_iter", "PARAMETER LST is NULL");
	if (!f)
		ft_error("ft_int_dlst_iter", "PARAMETER F is NULL");
	while (lst != NULL)
	{
		f(&lst->content);
		lst = lst->next;
	}
}

t_int_dlist	*ft_int_dlst_last(t_int_dlist *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

t_int_dlist	*ft_int_dlst_map(t_int_dlist *lst, int (*f)(int))
{
	t_int_dlist	*head;
	t_int_dlist	*last;
	t_int_dlist	*tmp;

	if (!lst || !f)
		ft_error("ft_int_dlst_map", "PARAMETERS LST or F are NULL");
	head = ft_int_dlst_new(f(lst->content));
	if (!head)
		return (NULL);
	last = head;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_int_dlst_new(f(lst->content));
		if (!tmp)
		{
			ft_int_dlst_clear(&head);
			return (NULL);
		}
		last->next = tmp;
		last = last->next;
		lst = lst->next;
	}
	return (head);
}

size_t	ft_int_dlst_size(t_int_dlist *lst)
{
	size_t	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
