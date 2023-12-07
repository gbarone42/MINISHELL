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

    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        printf("Error: Unable to get the current working directory\n");
        return;
    }

    // Free the previous prompt if it exists
    free(shell->prompt);

    // Get the user name
    char *user = ft_strjoin(PURPLE, getenv("USER"));
    if (!user)
    {
        perror("Error: Unable to allocate memory for user\n");
        exit(EXIT_FAILURE); // or return if you want to handle the error
    }

    // Get the prompt suffix
    char *prompt_suffix = ft_strjoin("@ASHellKETCHUM" CLR_RMV " > ", "");
    if (!prompt_suffix)
    {
        perror("Error: Unable to allocate memory for prompt_suffix\n");
        free(user);
        exit(EXIT_FAILURE); // or return if you want to handle the error
    }

    // Create a new prompt with the user name, prompt suffix, and current directory
    shell->prompt = (char *)malloc(strlen(user) + strlen(prompt_suffix) + strlen(cwd) + 1);
    if (!shell->prompt)
    {
        perror("Error: Unable to allocate memory for the new prompt\n");
        free(user);
        free(prompt_suffix);
        exit(EXIT_FAILURE); // or return if you want to handle the error
    }

    // Construct the new prompt
    strcpy(shell->prompt, user);
    strcat(shell->prompt, cwd);
    strcat(shell->prompt, prompt_suffix);

    printf("Updated prompt: %s\n", shell->prompt);

    // Free temporary strings
    free(user);
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