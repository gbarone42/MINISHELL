#include "../../include/minishell.h"

void handle_env(t_shell *shell)
{
    t_evlist *current = shell->env_list; // Use env_list instead of env
    while (current)
    {
        printf("%s\n", current->value);
        current = current->next;
    }
}
