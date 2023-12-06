#include "../../include/minishell.h"

#ifndef PATH_MAX
#define PATH_MAX 4096

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
    if (path == NULL)
    {
        // No path provided, default to home directory
        path = getenv("HOME");
    }
    if (chdir(path) == 0)
    {   
        printf("Changed to directory: %s\n", path);
        update_prompt(shell);
    }
    else
    {
         perror("cd"); // Print an error message if chdir fails
    }
}


void update_prompt(t_shell *shell)
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        fprintf(stderr, "Error: Unable to get the current working directory\n");
        return;
    }
    if (shell->prompt == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for the new prompt\n");
        return;
    }
    printf("Updated prompt: %s\n", shell->prompt);

}