#include "../../include/minishell.h"


//here i use 
//getenv(), chdir(), getcwd(), perror()

#ifndef PATH_MAX
#define PATH_MAX 4096

#endif

void ft_handle_cd(t_shell *shell, char **args)
{
    printf("Input: %s\n", shell->input);
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
    if (shell->prompt == NULL)
    {
        perror("Error: Unable to allocate memory for the new prompt\n");
        return;
    }
    printf("Updated prompt: %s\n", shell->prompt);

}