/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:18:17 by filippo           #+#    #+#             */
/*   Updated: 2024/02/07 14:16:20 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_expd(t_tlist *t, size_t o, size_t *p_i)
{
	t_shell	*s;
	char	*expd;
	size_t	i;

	s = ft_ret_shell(NULL);
	i = *p_i;
	if (t->data[i] == '?')
	{
		expd = ft_itoa(g_exit);
		(*p_i)++;
	}
	else
		expd = ft_get_value_of(s, t->data + o, i - o);
	return (expd);
}

void	ft_expand_env_var(t_tlist *t, t_dsize_t o_i, \
	char *expd)
{
	t_ilist	*exp;

	while (t->next)
	{
		exp = t->expand;
		if (t->type == GENERAL_TOKEN)
		{
			while (exp)
			{
				o_i = (t_dsize_t){exp->index, exp->index + 1};
				while (ft_isalnum(t->data[o_i.y]) || t->data[o_i.y] == '_')
					o_i.y++;
				t->data[o_i.x++] = '\0';
				expd = ft_get_expd(t, o_i.x, &o_i.y);
				exp = exp->next;
				ft_update_ilist(exp, ft_strlen(expd) - (o_i.y - o_i.x + 1));
				expd = ft_strjoin_and_free_second(t->data, expd);
				expd = ft_strjoin_and_free_first(expd, t->data + o_i.y);
				free(t->data);
				t->data = expd;
			}
		}
		t = t->next;
	}
}
