#include "../../include/minishell.h"

#ifndef PATH_MAX
#define PATH_MAX 4096 // You can choose a value that makes sense for your application

#endif

void ft_handle_cd(t_shell *shell, char **args)
{
    printf("Input: %s\n", shell->input);
    if (args && args[1])
    {
        // cd has arguments, attempt to change directory
        change_directory(shell, args[1]);
    }
    else
    {
        // cd without arguments, go to the home directory
        change_directory(shell, NULL);
    }
}

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