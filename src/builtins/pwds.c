#include "../../include/minishell.h"


#ifndef PATH_MAX
#define PATH_MAX 4096 // You can choose a value that makes sense for your application

#endif

void print_current_directory(void)
{
    char current_directory[PATH_MAX];
    if (getcwd(current_directory, sizeof(current_directory)) != NULL) {
        printf("%s\n", current_directory);
    } else {
        perror("getcwd");
    }
}
