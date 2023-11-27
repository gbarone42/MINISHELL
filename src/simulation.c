#include "../include/minishell.h"
#include <time.h>


void ft_minishell_simulator(t_shell *shell)
{
    t_pars  *command;

    while (1)
    {
            errno = 0;
            shell->input = readline(shell->prompt);
            //printf("%s\n", shell->prompt);
        if (shell->input == NULL)
        {
            ft_ctrld(shell);
        }
        builtins_call(shell);
        add_to_history(shell->input); 
        if (ft_isvalid(shell->input))
        {
                // If you want built-in commands to be checked and executed
                // regardless of the validity of the input (as long as it's
                // not explicitly handled in builtins_call), then keeping it
                // outside the block is the better option.
                // If you want built-in commands to be dependent on the validity
                // of the input, you can move it inside the block.
                // so should i put builtins_call(shell) here or not?

				//printf("\n\n                     42\n");
			    shell_parser(shell, &command);
			    // if (shell->exit == 0)
				// shell_executor(&command, shell);
	    }
        free(shell->input);
    }
}

