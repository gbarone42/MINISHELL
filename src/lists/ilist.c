/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:56:34 by filippo           #+#    #+#             */
/*   Updated: 2024/02/05 20:42:28 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ilist	*ft_new_ilnode(size_t index)
{
	t_ilist	*output;

	output = ft_calloc(1, sizeof(*output));
	if (!output)
		return (NULL);
	output->index = index;
	output->next = NULL;
	return (output);
}

void	ft_app_ilist(t_ilist **p_last, size_t index)
{
	t_ilist	*last;
	t_ilist	*new;

	new = ft_new_ilnode(index);
	if (!new)
		ft_free_and_err(ft_ret_shell(NULL), "FT_NEW_ILNODE", errno = ENOMEM);
	last = *p_last;
	if (!last)
		*p_last = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	ft_free_ilist(t_ilist *head)
{
	t_ilist	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_update_ilist(t_ilist *expand, int diff)
{
	while (expand)
	{
		expand->index += diff;
		expand = expand->next;
	}
}
