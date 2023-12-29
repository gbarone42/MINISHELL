/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:52:44 by filippo           #+#    #+#             */
/*   Updated: 2023/12/29 11:52:47 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

t_tlist	*ft_new_tlnode(size_t len)
{
	char	*value;
	t_tlist	*output;

	value = ft_malloc_soul(++len * sizeof(char));
	if (!value)
		return (NULL);
	output = malloc(sizeof(*output));
	if (!output)
	{
		free(value);
		return (NULL);
	}
	*value = '\0';
	output->data = value;
	output->type = NULL_TOKEN;
	output->next = NULL;
	return (output);
}

size_t	ft_app_tlist(size_t j, t_tlist **p_last, size_t len)
{
	t_shell	*shell;
	t_tlist	*last;
	t_tlist	*new;

	if (j)
	{
		shell = ft_ret_shell(NULL);
		last = *p_last;
		last->data[j] = '\0';
		new = ft_new_tlnode(len);
		if (!new)
			ft_free_and_err(shell, "FT_NEW_TLNODE", errno = ENOMEM);
		last->next = new;
		*p_last = new;
		shell->ntokens++;
	}
	return (0);
}

void	ft_free_tlist(t_tlist *head)
{
	t_tlist	*tmp;

	while (head)
	{
		free(head->data);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

size_t	ft_app_tlist_decorator(size_t j, t_tlist **p_last, char c, size_t len)
{
	t_tlist	*last;

	ft_app_tlist(j, p_last, len);
	last = *p_last;
	last->data[0] = c;
	last->type = c;
	return (ft_app_tlist(1, p_last, len - 1));
}
