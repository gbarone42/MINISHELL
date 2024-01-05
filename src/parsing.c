#include "../include/minishell.h"

void	shell_parser(t_shell *shell, t_pars **command)
{
    (void)shell;
    (void)command;

    char		**inputs;
    inputs = input_handler(shell);
    if (inputs == NULL)
    {
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

    printf("Number of substring: %d\n", pipes);


    return NULL;

}

int ft_count_pipes(const char *s, char pipe)
{
    size_t i = 0; //per iterare la stringa INPUT
    size_t n = 0; // conta il numero delle substringhe
    size_t len = 0; // conta la lunghezza di ogni substr

    while (1)
    {
        if (s[i] == pipe || s[i] == '\0')
        {
            if (len > 0)
            {
                n++;
                len = 0;
            }
            else if (n == 0 && s[i] == pipe)
            {
                return -1;
            }
        }
        else if (s[i] == DOUBLE_QUOTE || s[i] == SINGLE_QUOTE)
        {
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
        return -1;
    }

    quote = s[*i];
    (*i)++;
    while (s[*i] && s[*i] != quote)
    {
        if (s[*i] == '\\' && s[*i + 1] == quote)
        {
            (*i) += 2;
        }
        else 
        {
            (*i)++;
        }
    }
    if (s[*i] == '\0')
    {
        return -1;
    }

    return 0;
}
