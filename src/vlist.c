/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:56:34 by filippo           #+#    #+#             */
/*   Updated: 2023/12/29 11:56:51 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

t_vlist	*ft_new_vlnode(char *value)
{
	t_vlist	*output;

	value = ft_strdup(value);
	if (!value)
		return (NULL);
	output = malloc(sizeof(*output));
	if (!output)
	{
		free(value);
		return (NULL);
	}
	output->value = value;
	output->next = NULL;
	output->prev = NULL;
	return (output);
}

t_vlist	*ft_append_vlist(t_vlist *last, char *value)
{
	t_vlist	*new;

	new = ft_new_vlnode(value);
	if (!new)
		return (NULL);
	last->next = new;
	new->prev = last;
	return (new);
}

void	ft_free_vlist(t_vlist *head)
{
	t_vlist	*tmp;

	while (head)
	{
		free(head->value);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
