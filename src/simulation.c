#include "../include/minishell.h"
#include <time.h>

void ft_minishell_simulator(t_shell *shell)
{
    t_pars *command;

    while (1)
    {
        errno = 0;
        shell->input = readline(shell->prompt);

        if (shell->input == NULL)
        {
            ft_ctrld(shell);
        }

        if (ft_isvalid(shell->input))
        {
            shell_parser(shell, &command);
            builtins_call(shell);
            add_to_history(shell->input);
        }
        else
        {
         printf("Invalid input detected!\n");
        }
        free(shell->input);
    }
}