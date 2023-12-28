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

size_t	ft_append_tlist(t_shell *shell, size_t j, t_tlist **p_last, size_t len)
{
	t_tlist	*last;
	t_tlist	*new;

	if (j)
	{
		last = *p_last;
		last->data[j] = '\0';
		new = ft_new_tlnode(len);
		if (!new)
			ft_free_and_err(shell, "FT_NEW_TLNODE", errno = ENOMEM);
		last->next = new;
		*p_last = new;
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

size_t	ft_append_tlist_decorator(t_shell *shell, t_dsize_t j_len, t_tlist **p_last, char c)
{
	t_tlist	*last;

	ft_append_tlist(shell, j_len.x, p_last, j_len.y);
	last = *p_last;
	last->data[0] = c;
	last->type = c;
	return (ft_append_tlist(shell, 1, p_last, j_len.y - 1));
}
