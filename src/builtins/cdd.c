#include "../../include/minishell.h"

//here i use 
//getenv(), chdir(), getcwd(), perror()

#ifndef PATH_MAX
#define PATH_MAX 4096

#endif

void ft_handle_cd(t_shell *shell, char **args)
{
    printf("Input for 'cd': %s\n", shell->input);
    if (args && args[1])
    {
        change_directory(shell, args[1]);
    }
    else
    {
        change_directory(shell, NULL);
    }
}

void change_directory(t_shell *shell, char *path)
{
    if (path == NULL)
    {
        path = getenv("HOME");
    }
    if (chdir(path) == 0)
    {   
        printf("Changed to directory: %s\n", path);
        update_prompt(shell);
    }
    else
    {
         perror("cd");
    }
}

void update_prompt(t_shell *shell)
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        printf("Error: Unable to get the current working directory\n");
        return;
    }

    free(shell->prompt);

    // Getting the user and formatting it with color
    char *user = ft_strjoin(PURPLE, getenv("USER"));
    if (!user)
    {
        perror("Error: Unable to allocate memory for user\n");
        exit(EXIT_FAILURE);
    }

    // Creating user with @ASHellKETCHUM
    char *user_at = ft_strjoin(user, "@ASHellKETCHUM");
    if (!user_at)
    {
        perror("Error: Unable to allocate memory for user_at\n");
        free(user);
        exit(EXIT_FAILURE);
    }

    // Adding a colon and space after @ASHellKETCHUM
    char *user_at_colon = ft_strjoin(user_at, ":");
    if (!user_at_colon)
    {
        perror("Error: Unable to allocate memory for user_at_colon\n");
        free(user);
        free(user_at);
        exit(EXIT_FAILURE);
    }

    // Creating the prompt suffix with color removal and dollar sign
    char *prompt_suffix = ft_strjoin(CLR_RMV, "$ ");
    if (!prompt_suffix)
    {
        perror("Error: Unable to allocate memory for prompt_suffix\n");
        free(user);
        free(user_at);
        free(user_at_colon);
        exit(EXIT_FAILURE);
    }

    // Allocating memory for the complete prompt
    shell->prompt = (char *)malloc(strlen(user_at_colon) + strlen(cwd) + strlen(prompt_suffix) + 1);
    if (!shell->prompt)
    {
        perror("Error: Unable to allocate memory for the new prompt\n");
        free(user);
        free(user_at);
        free(user_at_colon);
        free(prompt_suffix);
        exit(EXIT_FAILURE);
    }

    // Concatenating the strings to form the prompt
    strcpy(shell->prompt, user_at_colon);
    strcat(shell->prompt, cwd);
    strcat(shell->prompt, prompt_suffix);

    printf("Updated prompt: %s\n", shell->prompt);

    // Freeing the allocated memory
    free(user);
    free(user_at);
    free(user_at_colon);
    free(prompt_suffix);
}
// void update_prompt(t_shell *shell)
// {
//     char cwd[PATH_MAX];
    
//     // Get the current working directory
//     if (getcwd(cwd, sizeof(cwd)) == NULL)
//     {
//         perror("getcwd");
//         printf("Error: Unable to get the current working directory\n");
//         return;
//     }

//     // Free the previous prompt if it exists
//     free(shell->prompt);

//     // Create a new prompt with the current directory
//     shell->prompt = (char *)malloc(strlen(cwd) + strlen(" > ") + 1);
//     if (!shell->prompt)
//     {
//         perror("Error: Unable to allocate memory for the new prompt\n");
//         exit(EXIT_FAILURE); // or return if you want to handle the error
//     }

//     // Construct the new prompt
//     strcpy(shell->prompt, cwd);
//     strcat(shell->prompt, " > ");

//     printf("Updated prompt: %s\n", shell->prompt);
// }