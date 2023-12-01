#include "../../include/minishell.h"

void handle_env(t_shell *shell)
{
    // Print the list of environment variables
    char **env = shell->env;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}
