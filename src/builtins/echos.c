#include "../../include/minishell.h"


void handle_echo(char *input)
{
    char *text;
    int suppress_newline = 0;

    text = input + 4; // Skip the "echo" part

    // Skip leading whitespaces
    while (*text && (*text == ' ' || *text == '\t'))
    {
        text++;
    }

    // Check for the -n option
    if (ft_strncmp(text, "-n", 2) == 0) {
        suppress_newline = 1;
        text += 2; // Skip the -n option

        // Skip trailing whitespaces after -n
        while (*text && (*text == ' ' || *text == '\t')) {
            text++;
        }
    }

    // Print the text
    printf("%s", text);

    // Print a newline if -n option is not present
    if (!suppress_newline) {
        printf("\n");
    }
}

void handle_echo_n(char *input)
{
    char *text;
    int suppress_newline = 1; // Set suppress_newline to 1 for "echo -n"

    text = input + 7; // Skip the "echo -n" part

    // Skip leading whitespaces
    while (*text && (*text == ' ' || *text == '\t'))
    {
        text++;
    }

    // Print the text
    printf("%s", text);

    // Print a newline if -n option is not present
    if (!suppress_newline) {
        printf("\n");
    }
}