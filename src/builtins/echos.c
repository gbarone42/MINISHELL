#include "../../include/minishell.h"


void handle_echo(char **args)
{
    int newline = 1;  // By default, echo prints a newline at the end.

    // Check if the first argument is '-n', which suppresses the newline.
    if (args[1] && strcmp(args[1], "-n") == 0) {
        newline = 0;  // Do not print the newline at the end.
        args++;       // Skip the '-n' argument.
    }

    // Start from the first or second argument based on the presence of '-n'.
    for (int i = 1; args[i]; i++) {
        printf("%s", args[i]);
        if (args[i + 1] != NULL) {
            printf(" ");  // Print spaces between arguments.
        }
    }

    // Print a newline if not suppressed.
    if (newline) {
        printf("\n");
    }
}