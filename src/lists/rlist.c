/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:56:34 by filippo           #+#    #+#             */
/*   Updated: 2024/02/05 20:42:33 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_rlist	*ft_new_rlnode(int type, char *filename)
{
	t_rlist	*output;

	output = ft_calloc(1, sizeof(*output));
	if (!output)
		return (NULL);
	output->type = type;
	output->filename = filename;
	output->next = NULL;
	return (output);
}

void	ft_app_rlist(t_rlist **p_first, int type, char *filename)
{
	t_rlist	*first;
	t_rlist	*new;

	new = ft_new_rlnode(type, filename);
	if (!new)
		ft_free_and_err(ft_ret_shell(NULL), "FT_NEW_ILNODE", errno = ENOMEM);
	first = *p_first;
	if (!first)
		*p_first = new;
	else
	{
		while (first->next)
			first = first->next;
		first->next = new;
	}
}

void	ft_free_rlist(t_rlist *head)
{
	t_rlist	*tmp;

	while (head)
	{
		head->filename = ft_free_char(&head->filename);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
