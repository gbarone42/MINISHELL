#include "../../include/minishell.h"

//here i use getlogin_r()

void whoami_command()
{
    char username[1024];
    if (getlogin_r(username, sizeof(username)) == 0) {
        printf("super%s\n", username);
    } else {
        perror("getlogin_r");
    }
}