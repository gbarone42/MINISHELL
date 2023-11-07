#include "../../include/minishell.h"

void	shell_parser(t_shell *shell, t_pars **command)
{
    (void)shell;
    (void)command;
    //char		**inputs;
    printf("\nPARSING IS COMING \n");

    char		**inputs;
    inputs = input_split(shell);

    //inputs = input_split(shell);
    //*inputs = NULL;
   
    // if (inputs == NULL)
	// return ;
    if (inputs == NULL)
    {
        // Handle the case when inputs is NULL
        return;
    }
}

char	**input_split(t_shell *shell)
{
    int     pipes;

    pipes = ft_count_pipes(shell->input,'|');
    if (pipes == -1)
	{
		write(STDERR_FILENO, "syntax error near unexpected token: \"|\"\n", 41);
		return (NULL);
	}

    
    return NULL;

}


int ft_count_pipes(const char *s, char pipe)
{
    size_t i = 0; //per iterare la stringa INPUT
    size_t n = 0; // conta il numero delle substringhe
    size_t len = 0; // conta la lunghezza di ogni substr

    while (1)
    {
        if (s[i] == pipe || s[i] == '\0') //check if the current character at index i in the input string s is equal to the delimiter character pipe or the null terminator '\0'.
        {
            if (len > 0)
            {
                n++;
                len = 0; //indicates that a non-empty substring was found
            }
            else if (n == 0 && s[i] == pipe)
            {
                return -1; //means that if the first character in the string is the delimiter pipe
            }
        }
        //If the current character is not the delimiter pipe or the null terminator,
        //it continues to the next step.
        else if (s[i] == DOUBLE_QUOTE || s[i] == SINGLE_QUOTE)
        {
            // Assuming pipe_numstr_quote is handling the quotes appropriately
            pipe_numstr_quote(s, &i);
        }
        else
        {
            len++;
        }
        if (s[i] == '\0')
        {
            break;
        }
        i++;
    }
    return n;
}

int pipe_numstr_quote(const char *s, size_t *i)
{
    char quote;

    if (!s || !i || *i >= ft_strlen(s)) //*i >= ft_strlen(s) suggerito da GPT i dont undderstand
    {
        // Error handling for invalid inputs or incomplete string
        return -1;
    }

    quote = s[*i];
    (*i)++;
    while (s[*i] && s[*i] != quote)//as long as the current character is not the null terminator and not the same as the starting quote character.
    {
        // Consider handling escaped quotes and special cases within the quoted section
        if (s[*i] == '\\' && s[*i + 1] == quote)
        {
            (*i) += 2; // Skip escaped quotes
        }
        else 
        {
            (*i)++;
        }
    }
    if (s[*i] == '\0')
    {
        // Error handling for incomplete quoted section
        return -1;
    }

    return 0;
}



// int	pipe_numstr(const char *s, char pipe)
// {
// 	size_t	i;
// 	size_t	n;
// 	size_t	len;

// 	i = 0;
// 	n = 0;
// 	len = 0;
// 	while (1)
// 	{
// 		if (s[i] == pipe || s[i] == '\0')
// 			pipe_numstr_add(&n, &len);
// 		if (s[i] == pipe && n == 0)
// 			return (-1);
// 		else if (s[i] == DOUBLE_QUOTE || s[i] == SINGLE_QUOTE)
// 			pipe_numstr_quote(s, &i);
// 		else
// 			len++;
// 		if (s[i] == '\0')
// 			break ;
// 		i++;
// 	}
// 	return (n);
// }



// void	shell_parser(t_shell *shell, t_pars **command)
// {
// 	t_tok		*token;
// 	char		**inputs;

// 	*command = NULL;
// 	token = NULL;
// 	inputs = input_split(shell);
// 	if (inputs == NULL)
// 		return ;
// 	pars_loop(inputs, token, command, shell);
// 	tok_free(token);
// 	lex_free_inputs(inputs);
// }




// char	**input_split(t_shell *shell)
// {
// 	int		pipes;
// 	char	**inputs;

// 	pipes = pipe_numstr(shell->input, '|');
// 	if (pipes == -1)
// 	{
// 		write(STDERR_FILENO, "syntax error near unexpected token: \"|\"\n", 41);
// 		g_exit = 1;
// 		shell->exit = g_exit;
// 		return (NULL);
// 	}
// 	if (pipes > 1)
// 		inputs = pipe_split(shell->input, '|');
// 	else
// 	{
// 		inputs = (char **)ft_calloc(2, sizeof(char *));
// 		inputs[0] = ft_strdup(shell->input);
// 		inputs[1] = NULL;
// 	}
// 	return (inputs);
// }





// int	pipe_numstr_quote(const char *s, size_t *i)
// {
// 	char	quote;

// 	quote = s[*i];
// 	(*i)++;
// 	while (s[*i] && s[*i] != quote)
// 		(*i)++;
// 	if (s[*i] == '\0')
// 		return (1);
// 	return (0);
// }

// void	pipe_numstr_add(size_t *n, size_t *len)
// {
// 	if (*len > 0)
// 		(*n)++;
// 	*len = 0;
// }

// int	pipe_numstr(const char *s, char pipe)
// {
// 	size_t	i;
// 	size_t	n;
// 	size_t	len;

// 	i = 0;
// 	n = 0;
// 	len = 0;
// 	while (1)
// 	{
// 		if (s[i] == pipe || s[i] == '\0')
// 			pipe_numstr_add(&n, &len);
// 		if (s[i] == pipe && n == 0)
// 			return (-1);
// 		else if (s[i] == DOUBLE_QUOTE || s[i] == SINGLE_QUOTE)
// 			pipe_numstr_quote(s, &i);
// 		else
// 			len++;
// 		if (s[i] == '\0')
// 			break ;
// 		i++;
// 	}
// 	return (n);
// }








// #include "minishell.h"

// void	pipe_splitter_quotes(const char *s, size_t *i, size_t *len)
// {
// 	char	quote;

// 	quote = s[*i];
// 	(*i)++;
// 	(*len)++;
// 	while (s[*i] && s[*i] != quote)
// 	{
// 		(*i)++;
// 		(*len)++;
// 	}
// 	(*len)++;
// }

// char	*pipe_splitter_add(const char *s, size_t *i, size_t *len)
// {
// 	char	*tok;

// 	if (*len > 0)
// 		tok = ft_substr(s, (unsigned int)(*i - *len), *len);
// 	else
// 		tok = NULL;
// 	*len = 0;
// 	return (tok);
// }

// void	pipe_splitter(const char *s, char pipe, char **split, size_t n)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	len;

// 	i = 0;
// 	j = 0;
// 	len = 0;
// 	while (j < n)
// 	{
// 		if (s[i] == pipe || s[i] == '\0')
// 		{
// 			split[j] = pipe_splitter_add(s, &i, &len);
// 			j++;
// 		}
// 		else if (s[i] == DOUBLE_QUOTE || s[i] == SINGLE_QUOTE)
// 			pipe_splitter_quotes(s, &i, &len);
// 		else
// 			len++;
// 		i++;
// 	}
// }

// char	**pipe_split(const char *s, char pipe)
// {
// 	char	**split;
// 	int		n;

// 	n = pipe_numstr(s, pipe);
// 	split = malloc(sizeof(*split) * ((size_t)n + 1));
// 	pipe_splitter(s, pipe, split, n);
// 	split[n] = NULL;
// 	return (split);
// }
