#include "../../include/minishell.h"

//here i use getcwd()
#ifndef PATH_MAX
#define PATH_MAX 4096

#endif

void print_current_directory(void)
{
    char current_directory[PATH_MAX];
    if (getcwd(current_directory, sizeof(current_directory)) != NULL)
    {
        printf("%s\n", current_directory);
    } else
    {
        perror("getcwd");
    }
}
