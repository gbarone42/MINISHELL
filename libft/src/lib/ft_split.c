/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:29:04 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/22 18:09:16 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INITIAL_LEN	100

static char	**ft_free_and_return(char **output, int null)
{
	size_t	index;
	char	**tmp;
	char	*str;

	if (null)
	{
		index = 2;
		str = output[index++];
		while (str)
		{
			free(str);
			str = output[index++];
		}
		free(output);
		return (NULL);
	}
	index = (size_t)(output[0] - output[1]);
	tmp = output;
	output = ft_calloc(sizeof(char *), index + 1);
	if (!output)
		return (ft_free_and_return(tmp, 1));
	while (index--)
		output[index] = tmp[2 + index];
	free(tmp);
	return (output);
}

static char	**ft_init_arr(size_t len)
{
	char	**output;

	output = ft_calloc(sizeof(char *), (len + 2));
	if (!output)
		return (NULL);
	output[0] = (char *) len;
	output[1] = (char *) len;
	return (output);
}

static int	ft_concat(char ***input, char *next_str)
{
	char	**tmp;
	size_t	len;
	size_t	n;

	tmp = *input;
	len = (size_t) tmp[0];
	n = (size_t) tmp[1];
	if (!n)
	{
		*input = ft_init_arr(len * 2);
		if (!*input)
			return (0);
		while (len--)
			(*input)[2 + len] = tmp[2 + len];
		len = (size_t) tmp[0];
		(*input)[len + 2] = next_str;
		(*input)[1] = (char *)(len - 1);
		free(tmp);
	}
	else
	{
		(*input)[len - n + 2] = next_str;
		(*input)[1] = (char *)(n - 1);
	}
	return (1);
}

static char	*ft_len_and_str(char *input, char c, size_t *len)
{
	uintptr_t	tmp;
	char		*output;

	output = input;
	tmp = (uintptr_t) ft_strchr(input, c);
	if (tmp)
		tmp -= (uintptr_t) input;
	else
		tmp = (uintptr_t)(ft_strchr(input, '\0') - input);
	if (tmp)
		output = ft_substr(input, 0, tmp);
	*len = tmp;
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	index;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	output = ft_init_arr(INITIAL_LEN);
	if (!output)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str = ft_len_and_str((char *) s + index, c, &len);
		if (!str || (len && !ft_concat(&output, str)))
			return (ft_free_and_return(output, 1));
		if (s[index + len])
			index += len + 1;
		else
			index += len;
	}
	return (ft_free_and_return(output, 0));
}
