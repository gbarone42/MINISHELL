/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:19 by gbarone           #+#    #+#             */
/*   Updated: 2024/02/05 20:42:02 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strtok(char *str, char sep)
{
	static char	*last = NULL;
	char		*token_start;

	if (str != NULL)
	{
		last = str;
	}
	else if (last == NULL || *last == '\0')
	{
		return (NULL);
	}
	token_start = last;
	while (*last != '\0' && *last != sep)
	{
		last++;
	}
	if (*last != '\0')
	{
		*last = '\0';
		last++;
	}
	return (token_start);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void		*new_ptr;
	size_t		copy_size;

	if (ptr == NULL)
		return (ft_calloc(1, new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(1, new_size);
	if (new_ptr == NULL)
	{
		perror("Memory allocation failed for realloc.\n");
		exit(EXIT_FAILURE);
	}
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*saved;

	saved = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (saved);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*saved;

	saved = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (saved);
}
