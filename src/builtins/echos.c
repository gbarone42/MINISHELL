#include "../../include/minishell.h"


void handle_echo(char *input)
{
    char *text;
    int suppress_newline = 0;

    text = input + 4;
    while (*text && (*text == ' ' || *text == '\t'))
    {
        text++;
    }
    if (ft_strncmp(text, "-n", 2) == 0) {
        suppress_newline = 1;
        text += 2;
        while (*text && (*text == ' ' || *text == '\t')) {
            text++;
        }
    }
    printf("%s", text);
    if (!suppress_newline) {
        printf("\n");
    }
}

void handle_echo_n(char *input)
{
    char *text;
    int suppress_newline = 1;

    text = input + 7;
    while (*text && (*text == ' ' || *text == '\t'))
    {
        text++;
    }
    printf("%s", text);
    if (!suppress_newline) {
        printf("\n");
    }
}