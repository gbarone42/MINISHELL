#include "../../include/minishell.h"

void whoami_command()
{
    char username[1024];
    if (getlogin_r(username, sizeof(username)) == 0) {
        printf("super%s\n", username);
    } else {
        perror("getlogin_r");
    }
}