#include "../include/minishell.h"
#include <time.h>

#ifndef PATH_MAX
#define PATH_MAX 4096 // You can choose a value that makes sense for your application

#endif



// void find_files(char *path, char *filename)
// {
//     DIR *dir;
//     struct dirent *entry;

//     if ((dir = opendir(path)) != NULL) {
//         while ((entry = readdir(dir)) != NULL) {
//             if (strcmp(entry->d_name, filename) == 0) {
//                 printf("%s/%s\n", path, entry->d_name);
//             }
//         }
//         closedir(dir);
//     } else {
//         perror("opendir() error");
//     }
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

