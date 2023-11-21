#include "../../include/minishell.h"

void handle_echo(char *input)
{
    char *text = input + 5; // Skip the "echo " part
    int suppress_newline = 0;

    // Check for the -n option
    if (ft_strncmp(text, "-n ", 3) == 0) {
        suppress_newline = 1;
        text += 3; // Skip the -n option
    }

    // Print the text
    printf("%s", text);

    // Print a newline if -n option is not present
    if (!suppress_newline) {
        printf("\n");
    }
}