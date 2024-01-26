
#include "minishell.h"


char	*ft_strtok(char *str, char sep)
{
	static char *last = NULL;
	char 		*token_start;

	if (str != NULL)
	{
		last = str;
	}
	else if (last == NULL || *last == '\0')
	{
		return NULL;
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
	return token_start;
}

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return malloc(new_size);
	if (!new_size)
	{
		free(ptr);
		return NULL;
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		perror("Memory allocation failed for realloc.\n");
		exit(EXIT_FAILURE);
	}
	size_t copy_size = (old_size < new_size) ? old_size : new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return new_ptr;
}

char *ft_strcpy(char *dest, const char *src)
{
	char *saved = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return saved;
}


char *ft_strcat(char *dest, const char *src)
{
	char *saved = dest;
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
	return saved;
}