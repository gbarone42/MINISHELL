/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   export_unset.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sdel-gra <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/10 16:30:40 by gbarone		   #+#	#+#			 */
/*   Updated: 2024/01/25 21:54:56 by sdel-gra		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	handle_envv(t_shell *shell)
{
	char	**env;

	env = shell->env_list;
	while (*env)
	{
		printf("declare -x %s\n", *env);
		env++;
	}
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
	{
		return (char *)haystack;
	}
	const char *p = haystack;
	while (*p != '\0')
	{
		const char *begin = p;
		const char *pattern = needle;
		while (*begin != '\0' && *pattern != '\0' && *begin == *pattern)
		{
			begin++;
			pattern++;
		}
		if (*pattern == '\0')
		{
			return (char *) p;
		}
		p++;
	}
	return (NULL);
}

void	remove_env_variable(t_shell *shell, const char *var_name)
{
	int j, k;
	
	j = 0;
	while (shell->env_list[j] != NULL)
	{
		if (ft_strstr(shell->env_list[j], var_name) == shell->env_list[j])
		{
			printf("Unsetting: %s\n", shell->env_list[j]);
			free(shell->env_list[j]); // Free the memory for the matching environment variable

			// Shift remaining elements left to fill the gap
			k = j;
			while (shell->env_list[k] != NULL)
			{
				shell->env_list[k] = shell->env_list[k + 1];
				k++;
			}

			// Ensure the last pointer is NULL after shifting
			shell->env_list[k - 1] = NULL;

			break; // Break when a match is found
		}
		j++;
	}
}

void handle_unset(t_shell *shell, char **args)
{
	int i;

	if (args[1] == NULL)
	{
		printf("Usage: unset <variable>\n");
		return;
	}
	i = 1;
	while (args[i] != NULL)
	{
		remove_env_variable(shell, args[i]);
		i++;
	}
}

char *ft_strtok(char *str, char sep)
{
	static char *last = NULL;

	if (str != NULL)
	{
		last = str;
	} else if (last == NULL || *last == '\0')
	{
		return NULL;
	}
	char *token_start = last;
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

bool contains_invalid_characters(const char *str)
{
	int i;
	i = 0;
	// Check first character
	if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))
	{
		return (true);
	}
	i = 1;
	// Check the rest of the string
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
		{
			return (true);
		}
		i++;
	}
	return (false);
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
	*dest = '\0';  // Ensure the destination is null-terminated
	return saved;
}


char *ft_strcat(char *dest, const char *src)
{
	char *saved = dest;
	while (*dest)  // Move to the end of dest
	{
		dest++;
	}
	while (*src)  // Append each character of src to dest
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';  // Null-terminate the result
	return saved;
}




char *create_envv_variable(const char *name, const char *value)
{
    size_t size = ft_strlen(name) + 1; // +1 for '\0'
    if (value && *value)
    {
        size += ft_strlen(value) + 1; // +1 for '='
    }

    char *variable = (char *)malloc(size);
    if (!variable)
    {
        perror("Memory allocation failed for env variable.\n");
        exit(EXIT_FAILURE);
    }

    ft_strcpy(variable, name);
    if (value && *value)
    {
        ft_strcat(variable, "=");
        ft_strcat(variable, value);
    }

    return variable;
}


int find_envv_variable(t_shell *shell, const char *name, const char *value)
{
    int i = 0;
    while (shell->env_list[i] != NULL)
    {
        if (ft_strncmp(shell->env_list[i], name, ft_strlen(name)) == 0 &&
            (shell->env_list[i][ft_strlen(name)] == '=' || shell->env_list[i][ft_strlen(name)] == '\0'))
        {
            free(shell->env_list[i]);
            shell->env_list[i] = create_envv_variable(name, value);
            return 1; // Variable found and updated
        }
        i++;
    }
    return 0; // Variable not found
}


void add_new_envv_variable(t_shell *shell, const char *name, const char *value)
{
    int env_size = 0;
    while (shell->env_list[env_size] != NULL)
    {
        env_size++;
    }

    char *new_variable = create_envv_variable(name, value);

    char **new_env_list = (char **)ft_realloc(shell->env_list, env_size * sizeof(char *), (env_size + 2) * sizeof(char *));
    if (!new_env_list)
    {
        perror("Memory allocation failed for env array.\n");
        exit(EXIT_FAILURE);
    }

    new_env_list[env_size] = new_variable;
    new_env_list[env_size + 1] = NULL;

    shell->env_list = new_env_list;
}


void add_envv_variable(t_shell *shell, const char *name, const char *value)
{
    if (!find_envv_variable(shell, name, value))
    {
        add_new_envv_variable(shell, name, value);
    }
}


// void add_envv_variable(t_shell *shell, const char *name, const char *value)
// {
// 	char *new_variable = (char *)malloc(ft_strlen(name) + ft_strlen(value) + 2);
// 	if (!new_variable)
// 	{
// 		printf("Memory allocation failed for env variable.\n");
// 		exit(EXIT_FAILURE);
// 	}

// 	ft_strcpy(new_variable, name);
// 	//strcat(new_variable, "=");
// 	ft_strcat(new_variable, value);
// 	printf("New variable: %s\n", new_variable);
// 	int found = 0;
// 	for (int i = 0; shell->env_list[i] != NULL; ++i)
// 	{
// 		if (ft_strncmp(shell->env_list[i], name, ft_strlen(name)) == 0 && shell->env_list[i][ft_strlen(name)] == '=')
// 		{
// 			free(shell->env_list[i]);
// 			shell->env_list[i] = new_variable;
// 			found = 1;
// 			break;
// 		}
// 	}
// 	if (!found)
// 	{
// 		int env_size;
// 		env_size = 0;
// 		while (shell->env_list[env_size] != NULL)
// 		{
// 			env_size++;
// 		}

// 		shell->env_list = (char **)ft_realloc(shell->env_list, env_size * sizeof(char *), (env_size + 2) * sizeof(char *));
// 		if (!shell->env_list)
// 		{
// 			perror("Memory allocation failed for env array.\n");
// 			exit(EXIT_FAILURE);
// 		}

// 		shell->env_list[env_size] = new_variable;
// 		shell->env_list[env_size + 1] = NULL;
// 	}
// }




char *create_new_env_variable(const char *name, const char *value)
{
    char *new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
    if (!new_variable)
    {
        printf("Memory allocation failed for env variable.\n");
        exit(EXIT_FAILURE);
    }

    ft_strcpy(new_variable, name);
    ft_strcat(new_variable, "=");
    ft_strcat(new_variable, value);

    return new_variable;
}

int update_existing_variable(t_shell *shell, const char *name, char *new_variable)
{
    int i = 0;
    while (shell->env_list[i] != NULL)
    {
        if (ft_strncmp(shell->env_list[i], name, strlen(name)) == 0 && shell->env_list[i][strlen(name)] == '=')
        {
            free(shell->env_list[i]);
            shell->env_list[i] = new_variable;
            return 1; // Found and updated
        }
        i++;
    }
    return 0; // Not found
}

void add_new_variable(t_shell *shell, char *new_variable, int env_size)
{
    shell->env_list = (char **)realloc(shell->env_list, (env_size + 2) * sizeof(char *));
    if (!shell->env_list)
    {
        perror("Memory allocation failed for env array.\n");
        exit(EXIT_FAILURE);
    }

    shell->env_list[env_size] = new_variable;
    shell->env_list[env_size + 1] = NULL;
}

void add_env_variable(t_shell *shell, const char *name, const char *value)
{
    char *new_variable = create_new_env_variable(name, value);
    printf("New variable: %s\n", new_variable);

    int found = update_existing_variable(shell, name, new_variable);

    if (!found)
    {
        int env_size = 0;
        while (shell->env_list[env_size] != NULL) env_size++;
        add_new_variable(shell, new_variable, env_size);
    }
}









void process_env_variable(t_shell *shell, char *arg)
{
    char *name;
    char *value;

	name  = ft_strtok(arg, '=');
	value = ft_strtok(NULL, '=');
    if (name != NULL)
    {
        if (contains_invalid_characters(name))
            printf("Invalid variable name: %s\n", name);
        else
        {
            if (value == NULL)
            {
                add_envv_variable(shell, name, "");
            }
            else
            {
                add_env_variable(shell, name, value);
            }
        }
    }
    else
        printf("Invalid export syntax: %s\n", arg);
}

void handle_export(t_shell *shell, char **args)
{
    if (args[1] == NULL)
    {
        handle_envv(shell);
    }
    else
    {
        process_env_variable(shell, args[1]);
    }
}


