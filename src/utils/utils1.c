
#include "../../include/minishell.h"

void	ft_bzero(void *s, size_t n)
{
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

	printf("calloc working properly \n");
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

char	*ft_strdup(const char *s)
{
	char	*y;
	size_t	f;

	f = 0;
	y = malloc(ft_strlen((char *)s) + 1);
	if (!y)
		return (NULL);
	while (s[f] != '\0')
	{
		y[f] = s[f];
		f++;
	}
	y[f] = '\0';
	return (y);
}