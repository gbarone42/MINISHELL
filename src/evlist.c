/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evlist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:56:34 by filippo           #+#    #+#             */
/*   Updated: 2024/01/05 19:04:19 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_p.h"

t_evlist	*ft_new_evlnode(char *value)
{
	t_evlist	*output;

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

t_evlist	*ft_app_evlist(t_evlist *last, char *value)
{
	t_evlist	*new;

	new = ft_new_evlnode(value);
	if (!new)
		return (NULL);
	last->next = new;
	new->prev = last;
	return (new);
}

void	ft_free_evlist(t_evlist *head)
{
	t_evlist	*tmp;

	while (head)
	{
		free(head->value);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

char	*ft_get_value_of(char *key)
{
	char	*output = NULL;

	output = getenv(key);
	free(key);
	return (output);
}
