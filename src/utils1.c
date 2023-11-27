
#include "../include/minishell.h"
void	ft_bzero(void *s, size_t n)
{
	//printf("ft_bzero working properly \n");
	size_t			i;
	unsigned char	*r;

	r = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		r[i] = '\0';
		i++;
		n--;
	}
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	y;

	//printf("calloc working properly \n");
	y = size * count;
	if (count != 0 && size != y / count)
		return (NULL);
	p = (void *)malloc(y);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, y);
	return (p);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *y = malloc(len + 1);
    if (!y)
	{
        return NULL; // Handle allocation failure
    }
    ft_memcpy(y, s, len + 1); // Copy the string and the null terminator
    return y;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}