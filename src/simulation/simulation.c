#include "../../build/minishell.h"


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

            if (errno)  // If readline returned NULL and errno is set, an error occurred
            {
                perror("readline error");  // Print the system error message
                continue;  // Optionally, decide whether to continue or exit
            }
            // EOF received, exit the shell. EOF = end of file
            printf("\n"); // Print a newline for a clean exit after EOF.
            free(shell->input);
            shell_exit(shell);
        }
        if (!ft_strncmp(shell->input, "exit", 5))
        {  
            shell_exit(shell);
        }
        add_history(shell->input); //input or prompt?
        // if (!ft_strncmp(shell->input, "exit", 5))
        // {
            
        // }
        if (ft_isvalid(shell->input))
        {
				printf("VABENEEELOSTESSOOOOOOOOOOOOOOOO \n");
			    shell_parser(shell, &command);
			    // if (shell->exit == 0)
				// shell_executor(&command, shell);
	    }
        free(shell->input);
    }
}


