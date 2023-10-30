#include "../../include/minishell.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*p;
	int				l;
	int				j;

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


int	ft_countdel( const char *str, char del)
{
	int	i;
	int	countdel;

	i = 0;
	countdel = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == del)
			countdel++;
	}
	return (countdel + 1);
}

char	*ft_newsub(char **str, char c)
{
	int		i;
	char	*unptr;

	i = 0;
	while (str[0][i] != '\0' && str[0][i] != c)
		i++;
	unptr = malloc(sizeof(char) * (i + 1));
	if ( unptr == NULL )
		return ( NULL );
	ft_strlcpy(unptr, str[0], --i);
		i++;
	str[0] = str[0] + 1 + i;
	printf("%s\n" , unptr);
	return (unptr);
}

char	**ft_split(char const *s, char c)

{
	char	**p;
	int		i;
	int		countdel;

	countdel = ft_countdel(s, c);
	i = 0;
	p = (char **)malloc(sizeof (char *) * (countdel + 1));
	if ( p == NULL )
		return ( NULL );
	while (*s != '\0')
	{
		p[i] = ft_newsub((char **)&s, c);
		i++;
		
	}
	p[i] = 0;
	return (p);
}