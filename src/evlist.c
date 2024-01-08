/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evlist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:56:34 by filippo           #+#    #+#             */
/*   Updated: 2024/01/08 18:06:25 by fcorri           ###   ########.fr       */
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

char	*ft_get_value_of(t_shell *shell, char *key, size_t len)
{
	t_evlist	*envv;

	envv = shell->first_envv;
	while (envv)
	{
		if (!ft_strncmp(envv->value, key, len))
			return (ft_strdup(envv->value + len + 1));
		envv = envv->next;
	}
	return (ft_strdup(""));
}
