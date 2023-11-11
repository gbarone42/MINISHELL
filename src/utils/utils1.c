
#include "../../build/minishell.h"

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

// char	*ft_strdup(const char *s)
// {
// 	char	*y;
// 	size_t	f;

// 	f = 0;
// 	y = malloc(ft_strlen((char *)s) + 1);
// 	if (!y)
// 		return (NULL);
// 	while (s[f] != '\0')
// 	{
// 		y[f] = s[f];
// 		f++;
// 	}
// 	y[f] = '\0';
// 	return (y);
// }


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


// There is no check for the return value of malloc, ft_strdup, 
// readline, or other system/library calls that can fail.
// If any of these calls fail, the program should handle 
// the error appropriately.




// char *ft_strdup(char *s, int should_free)
// {
//     char    *y;
//     size_t  f;

//     f = 0;
//     y = malloc(ft_strlen(s) + 1);
//     if (!y)
//         return (NULL);
//     while (s[f] != '\0')
//     {
//         y[f] = s[f];
//         f++;
//     }
//     y[f] = '\0';

//     if (should_free)
//     {
//         free(s);
//     }

//     return (y);
// }


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