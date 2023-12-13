#include "../../include/minishell.h"

void echo_no_arguments()
{
    printf("\n");
}

// Function for echo with arguments but without '-n'.
void echo_with_arguments(char **args) {
    for (int i = 1; args[i]; i++) {
        printf("%s", args[i]);
        if (args[i + 1] != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

// Function for echo with '-n' argument.
void echo_with_n_argument(char **args) {
    args++;  // Skip the '-n' argument.
    for (int i = 1; args[i]; i++) {
        printf("%s", args[i]);
        if (args[i + 1] != NULL) {
            printf(" ");
        }
    }
    // No newline printed.
}

// Main function to decide which echo function to call.
void handle_echo(char **args) {
    if (args[1] == NULL) {
        // No arguments provided.
        echo_no_arguments();
    } else if (strcmp(args[1], "-n") == 0) {
        // '-n' argument is provided.
        echo_with_n_argument(args);
    } else {
        // Other arguments are provided.
        echo_with_arguments(args);
    }
}