/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:53:11 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/21 18:55:58 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	if not NULL, free pointer and set to NULL 
	RETURN the pointer
*/
char	*ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (*ptr);
}

/*
	strchr but return the index of the character instead the pointer
	-1 means that we did not found the char
*/
int	ft_strchr_i(const char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (!c && !s)
	{
		return (0);
	}
	if (s && s[i] == c)
		return (i);
	return (-1);
}

// alloc mem and assign \0 to all the string 
char	*ft_calloc_char(size_t nmemb)
{
	char		*p;
	size_t		i;

	i = 0;
	p = (void *)malloc(nmemb * sizeof(char));
	if (!p)
		return (NULL);
	while (i < nmemb)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

/* 
	join 2 string and free the s1
*/
char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = ft_calloc_char(ft_strchr_i(s1, '\0') + ft_strchr_i(s2, '\0') + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	ft_free(&s1);
	return (res);
}

/*
	split from s to len and from (s + len) to end of str
	return from s to len 
*/
char	*ft_substr_s(char **s, int len)
{
	char	*out;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (len == 0)
	{
		return (*s);
	}
	out = ft_calloc_char(len + 1);
	while (*s && (*s)[i] && i < len)
	{
		out[i] = (*s)[i];
		i++;
	}
	while (*s && (*s)[i])
	{
		(*s)[j] = (*s)[i];
		i++;
		j++;
	}
	if (!(*s)[i])
		(*s)[j] = (*s)[i];
	return (out);
}

/*
int main(int argc, char const *argv[])
{
	int 	fd = open("../read_error.txt", O_RDONLY);
	char	*p;
	p = NULL;
	do
	{
		p = get_next_line(fd);
		printf("%s", p);
		p = get_next_line(fd);
		printf("%s", p);
		p = get_next_line(-1);
		printf("%s", p);
	} while (p);
	
	return 0;
}*/
