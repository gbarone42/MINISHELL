#include "../include/minishell.h"
#include <time.h>

void handle_basic_builtins(t_shell *shell) {
    if (!ft_strncmp(shell->input, "exit", 5))
    {
        shell_exit(shell);
    }
    else if (!ft_strncmp(shell->input, "echo -n", 7))
    {
        handle_echo_n(shell->input);
    }
    else if (!ft_strncmp(shell->input, "echo", 4))
    {
        handle_echo(shell->input);
    }
    else if (!ft_strncmp(shell->input, "pwd", 3))
    {
        print_current_directory();
    }
    else if (!ft_strncmp(shell->input, "history", 7))
    {
        display_history();
    }
}

// Function to handle other built-in commands (clear, ls, time, whoami)
void handle_other_builtins(t_shell *shell)
{
    if (!ft_strncmp(shell->input, "clear", 5))
    {
        clear_screen();
    }
    else if (!ft_strncmp(shell->input, "ls", 2))
    {
        print_current_directory_contents();
    }
    else if (!ft_strncmp(shell->input, "time", 4))
    {
        print_current_time();
    }
    else if (!ft_strncmp(shell->input, "whoami", 6))
    {
        whoami_command();
    }
}

void builtins_call(t_shell *shell)
{
    handle_basic_builtins(shell);
    handle_other_builtins(shell);
}

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
                write(STDERR_FILENO, "readline error: ", 17);  // Print the system error message
                continue;  // Optionally, decide whether to continue or exit
            }
        // EOF received, exit the shell. EOF = end of file
        printf("\n"); // Print a newline for a clean exit after EOF.
        free(shell->input);
        shell_exit(shell);
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

