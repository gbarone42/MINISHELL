#include "../include/minishell.h"
#include <time.h>

#ifndef PATH_MAX
#define PATH_MAX 4096 // You can choose a value that makes sense for your application

#endif

void change_directory(t_shell *shell, char *path)
{
    // Use path to change the directory
    // If path is NULL, go to the home directory

    if (path == NULL)
    {
        // No path provided, default to home directory
        path = getenv("HOME");
    }

    // Implement the logic for changing the directory
    if (chdir(path) == 0)
    {   
        printf("Changed to directory: %s\n", path);
    }
    else
    {
         perror("cd"); // Print an error message if chdir fails
    }
    // Optionally, update the prompt to show the new directory
    update_prompt(shell);
}


void update_prompt(t_shell *shell)
{
    // Update the prompt based on the new current working directory
    // For example, you can use getcwd() to get the current working directory

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        fprintf(stderr, "Error: Unable to get current working directory\n");
        return;
    }

    // Update the prompt with the new current working directory
    free(shell->prompt); // Free the old prompt
    shell->prompt = ft_strjoin(PURPLE, getenv("USER")); // You can customize this part
    shell->prompt = ft_strjoin(shell->prompt, "@");
    shell->prompt = ft_strjoin(shell->prompt, cwd);
    shell->prompt = ft_strjoin(shell->prompt, CLR_RMV);
    shell->prompt = ft_strjoin(shell->prompt, " > ");
    printf("Updated prompt: %s\n", shell->prompt);
}
void handle_unset(t_shell *shell)
{
    // Check if there are arguments after 'unset'
    if (shell->input && shell->input[0] != '\0') {
        // Unset the environment variable
        unsetenv(shell->input);
    } else {
        // If no arguments provided, print an error message
        printf("Usage: unset VARIABLE_NAME\n");
    }
}

void handle_env(t_shell *shell)
{
    // Print the list of environment variables
    char **env = shell->env;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

void handle_suspend(void)
{
    // Send a SIGTSTP signal to suspend the shell
    if (kill(getpid(), SIGTSTP) == -1) {
        perror("suspend");
    }
}


void handle_export(t_shell *shell)
{
    // Check if there are arguments after 'export'
    if (shell->input && shell->input[0] != '\0')
    {
        // Split the input into variable and value
        char **args = ft_split(shell->input, '=');

        // Check if the split was successful and contains at least one element
        if (args && args[0])
        {
            // Set the environment variable
            if (args[1])
                setenv(args[0], args[1], 1);
            else
                setenv(args[0], "", 1);
        }

        // Free the allocated memory
        free(args);
    }
    else
    {
        // If no arguments provided, print the list of environment variables
        char **env = shell->env;
        while (*env) {
            printf("%s\n", *env);
            env++;
        }
    }
}

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

void handle_basic_builtins(t_shell *shell)
{
    if (!ft_strncmp(shell->input, "exit", 5))
    {
        shell_exit(shell);
    }
    else if (!ft_strncmp(shell->input, "cd", 3))
    {
        char **args = ft_split(shell->input, ' ');

        if (args && args[1])
        {
            // cd has arguments, attempt to change directory
            change_directory(shell, args[1]);
            free(args);
        }
        else
        {
            // cd without arguments, go to the home directory
            change_directory(shell, NULL);
        }
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
    else if (!ft_strncmp(shell->input, "export", 6))
    {
        handle_export(shell);
    }
    else if (!ft_strncmp(shell->input, "unset", 5))
    {
        handle_unset(shell);
    }
    else if (!ft_strncmp(shell->input, "env", 3))
    {
        handle_env(shell);
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
    else if (!ft_strncmp(shell->input, "suspend", 7))
    {
        handle_suspend();
    }
    // else if (!ft_strncmp(shell->input, "find", 4))
    // {
    //     char **args = ft_split(shell->input, ' ');

    //     if (args && args[1])
    //     {
    //         find_files(".", args[1]);  // Assuming you want to search in the current directory
    //         free(args);
    //     }
    //     else
    //     {
    //         printf("Usage: find FILENAME\n");
    //     }
    // }
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

