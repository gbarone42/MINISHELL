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
            // Valid input, proceed with parsing and execution
            shell_parser(shell, &command);
            // if (shell->exit == 0)
            //     shell_executor(&command, shell);
            
            // Call builtins and add to history after validity check
            builtins_call(shell);
            add_to_history(shell->input);
        }
        else
        {
        // Invalid input, handle the error or take appropriate action
         printf("Invalid input detected!\n");
        }
        free(shell->input);
    }
}

// void ft_minishell_simulator(t_shell *shell)
// {
//     t_pars  *command;

//     while (1)
//     {
//             errno = 0;
//             shell->input = readline(shell->prompt);
//             //printf("%s\n", shell->prompt);
//         if (shell->input == NULL)
//         {
//             ft_ctrld(shell);
//         }
//         builtins_call(shell);
//         add_to_history(shell->input); 
//         if (ft_isvalid(shell->input))
//         {
// 			    shell_parser(shell, &command);
// 			    // if (shell->exit == 0)
// 				// shell_executor(&command, shell);
// 	    }
//         free(shell->input);
//     }
// }

