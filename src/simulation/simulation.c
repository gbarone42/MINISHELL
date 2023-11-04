#include "../../include/minishell.h"

// static void	ft_norm_signall(void)
// {
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGINT, signal_handler);
// }


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
            shell_exit(shell);
        }
        if (!ft_strncmp(shell->input, "exit", 5))
        {  
            shell_exit(shell);
        }
        add_history(shell->input); //input or prompt?
        if (ft_isvalid(shell->input))
        {
				printf("VABENEEELOSTESSOOOOOOOOOOOOOOOO \n");
			    shell_parser(shell, &command);
			    // if (shell->exit == 0)
				// shell_executor(&command, shell);
	    }
    }
}





// void ft_minishell_simulator(t_shell *shell)
// {
// 	int	print_count = 0;

//     while (g_exit == 0)
//     {
//         if (print_count <= 10)
//         {   
//             //ft_norm_signall();
//             shell->input = readline(shell->prompt);
//             //printf("%s\n", shell->prompt);
//             add_history(shell->input); //input or prompt?
//             if (!ft_strncmp(shell->input, "exit", 5) || shell->input == NULL)
//             {  
                
// 		        printf("      EXIT   THE    MINISHELL   SIMULATION    \n");
//                 shell_exit(shell);
//             }

//             if (!ft_isvalid(shell->input))
//             {
// 				printf("VABENEEELOSTESSOOOOOOOOOOOOOOOO \n");
// 			    add_history(shell->input);
// 			    // shell_parser(shell, &command);
// 			    // if (shell->exit == 0)
// 				// shell_executor(&command, shell);
// 	    	}


//             print_count++;
//             sleep(3); // Adding a sleep of 1 second between iterations.
//         }
//         else
//         {
//             sleep(3); // This will ensure that the loop doesn't run too fast after the message is printed 3 times.
//         }
//     }
//     if (g_exit == 130)
//     {
//         printf("CTRL + C\n");
//     }
// }


