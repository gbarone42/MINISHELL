#include "../include/minishell.h"
void	shell_parser(t_shell *shell, t_pars **command)
{
    (void)shell;
    (void)command;
    //char		**inputs;
    //printf("\nPARSING IS COMING \n");

    char		**inputs;
    inputs = input_handler(shell);

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

char	**input_handler(t_shell *shell)
{
    int     pipes;

    pipes = ft_count_pipes(shell->input, PIPE);
    //printf("Number of substrings: %d\n", pipes); 
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
            pipe_handler_quote(s, &i);
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

int pipe_handler_quote(const char *s, size_t *i)
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

