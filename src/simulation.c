#include "../include/minishell.h"
#include <time.h>
// static void	ft_norm_signall(void)
// {
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGINT, signal_handler);
// }

// #ifndef PATH_MAX
// #define PATH_MAX 4096 // You can choose a value that makes sense for your application

// #endif

// #define HISTORY_SIZE 100

// char* history[HISTORY_SIZE];
// int history_count = 0;

// void add_to_history(char* command)
// {
//     if (history_count < HISTORY_SIZE)
//     {
//         history[history_count++] = strdup(command);
//     }
//     else
//     {
//         free(history[0]);
//         for (int i = 0; i < history_count - 1; ++i)
//         {
//             history[i] = history[i + 1];
//         }
//         history[history_count - 1] = strdup(command);
//     }
// }

// void display_history(void)
// {
//     for (int i = 0; i < history_count; ++i)
//     {
//         printf("%d: %s\n", i + 1, history[i]);
//     }
// }


// void print_current_directory(void)
// {
//     char current_directory[PATH_MAX];
//     if (getcwd(current_directory, sizeof(current_directory)) != NULL) {
//         printf("%s\n", current_directory);
//     } else {
//         perror("getcwd");
//     }
// }

// void print_current_directory_contents(void)
// {
//     DIR *dir = opendir(".");
//     struct dirent *entry;

//     if (dir == NULL) {
//         perror("opendir");
//         return;
//     }

//     while ((entry = readdir(dir)) != NULL) {
//         printf("%s\n", entry->d_name);
//     }

//     closedir(dir);
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
            write(STDERR_FILENO, "readline error: ", 17);  // Print the system error message
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
        else if (!ft_strncmp(shell->input, "clear", 5))
        {
            clear_screen();
        } 
        else if (!ft_strncmp(shell->input, "pwd", 3))
        {
            print_current_directory();
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
        else if (!ft_strncmp(shell->input, "history", 7))
        {
            display_history();
        }

        add_to_history(shell->input); 

        //add_history(shell->input); //input or prompt?
        // if (!ft_strncmp(shell->input, "exit", 5))
        // {
            
        // }
        if (ft_isvalid(shell->input))
        {
				printf("42\n");
			    shell_parser(shell, &command);
			    // if (shell->exit == 0)
				// shell_executor(&command, shell);
	    }
        free(shell->input);
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


