
#include "../include/minishell.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    unsigned int i;
    char *p;
    int l;
    int j;

    l = ft_strlen(s1) + ft_strlen(s2) + 1;
    p = malloc(l);
    if (!p)
        return (0);

    j = 0;
    i = 0;
    while (s1[i] != 0)
        p[j++] = s1[i++];
    i = 0;
    while (s2[i] != 0)
        p[j++] = s2[i++];
    p[j] = 0;

    return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}

int	ft_countdel(const char *str, char del)
{
	int	i;
	int	countdel;

	i = 0;
	countdel = 0;
	while (str[i] != '\0')
	{
		if (str[i] == del)
			countdel++;
		i++;
	}
	return (countdel + 1);
}

char *ft_newsub(char **str, char c)
{
    int i;
    char *unptr;

    i = 0;
    while ((*str)[i] != '\0' && (*str)[i] != c)
        i++;
    unptr = malloc(sizeof(char) * (i + 1));
    if (unptr == NULL)
        return (NULL);
    ft_strlcpy(unptr, *str, i + 1);
    *str = *str + i + ((*str)[i] == c ? 1 : 0);

    return (unptr);
}

char	**ft_split(const char *s, char c)
{
	char	**p;
	int		i;
	int		countdel;

	countdel = ft_countdel(s, c);
	i = 0;
	p = (char **)malloc(sizeof(char *) * (countdel + 1));
	if (p == NULL)
		return (NULL);
	while (*s != '\0')
	{
		p[i] = ft_newsub((char **)&s, c);
		i++;
	}
	p[i] = 0;
	return (p);
}
