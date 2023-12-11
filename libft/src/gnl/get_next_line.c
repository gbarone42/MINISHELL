/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:07:10 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/04 17:46:49 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"

static char	*ft_strndup_gnl(char *s, size_t len)
{
	char	*output;
	size_t	index;
	size_t	size;

	size = sizeof(unsigned long);
	output = ft_calloc_gnl(size, (len + 1) / size + 1);
	if (!output)
		return (NULL);
	index = -1;
	while (++index < len)
		output[index] = s[index];
	output[index] = '\0';
	return (output);
}

static char	*ft_strjoin_gnl(char **s1, char *s2, size_t br)
{
	char	*output;
	size_t	len1;
	size_t	index;
	size_t	size;

	if (!*s1)
		output = ft_strndup_gnl(s2, br);
	else
	{
		size = sizeof(unsigned long);
		len1 = ft_strchr_gnl(*s1, '\0') - *s1;
		output = ft_calloc_gnl(size, (len1 + br + 1) / size + 1);
		if (!output)
			return (NULL);
		index = -1;
		while (++index < len1)
			output[index] = (*s1)[index];
		index = -1;
		while (++index < br)
			output[len1 + index] = s2[index];
		output[len1 + index] = '\0';
		free(*s1);
	}
	*s1 = output;
	return (output);
}

static char	*ft_free_and_return(char **line, char *buffer, char *output)
{
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	free(buffer);
	return (output);
}

static char	*ft_return(char **line, char *newline, char *buffer)
{
	char	*output;
	char	*tmp;

	if (!**line)
		return (ft_free_and_return(line, buffer, NULL));
	if (newline)
	{
		output = ft_strndup_gnl(*line, newline - *line + 1);
		tmp = *line;
		*line = ft_strndup_gnl(newline + 1,
				ft_strchr_gnl(newline + 1, '\0') - (newline + 1));
		return (ft_free_and_return(&tmp, buffer, output));
	}
	tmp = *line;
	*line = NULL;
	return (ft_free_and_return(NULL, buffer, tmp));
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	ssize_t		br;
	char		*newline;
	size_t		size;

	size = sizeof(unsigned long);
	buffer = ft_calloc_gnl(size, BUFFER_SIZE / size + 1);
	if (fd < 0 || !buffer || BUFFER_SIZE <= 0)
		return (ft_free_and_return(&line, buffer, NULL));
	br = read(fd, buffer, BUFFER_SIZE);
	while (br > 0)
	{
		if (!ft_strjoin_gnl(&line, buffer, br))
			return (ft_free_and_return(&line, buffer, NULL));
		newline = ft_strchr_gnl(line, '\n');
		if (newline)
			return (ft_return(&line, newline, buffer));
		br = read(fd, buffer, BUFFER_SIZE);
	}
	if (line)
		return (ft_return(&line, ft_strchr_gnl(line, '\n'), buffer));
	return (ft_free_and_return(&line, buffer, NULL));
}
