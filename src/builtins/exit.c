#include "../../include/minishell.h"




void shell_exit(t_shell *shell)
{
    int i;

    rl_clear_history();
    if(shell->input)
    {
        free(shell->input);
    }
    if (shell->prompt) // if it's not NULL
    {
        free(shell->prompt);
    }
    if (shell->env)
    {
        i = 0;
        while (shell->env[i])
            free(shell->env[i++]);
        free(shell->env);
    }
    if (shell->paths)
    {
        i = 0;
        while (shell->paths[i])
            free(shell->paths[i++]);
        free(shell->paths);
    }
    if (shell->export)
    {
        i = 0;
        while (shell->export[i])
            free(shell->export[i++]);
        free(shell->export);
    }
    // Free history
    for (i = 0; i < history_count; ++i)
    {
        free(history[i]);
    }
    exit(g_exit);
}



// #ifndef PATH_MAX
// #define PATH_MAX 4096 // You can choose a value that makes sense for your application

// #endif



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




// The use of exit(g_exit); in shell_exit means that the main function’s return 0;
// is never reached. Depending on how you want to handle exit codes, this might be an issue.

// freeing components of shell. This should be done in all exit paths to prevent memory leaks.
/*
void freeing_my_shell(t_shell *my_shell)
{


		printf("@@@@@@@");
		 free((my_shell)->prompt);
        // // Free dynamically allocated members of t_shell
        // if ((my_shell)->prompt != NULL) {
        //     free((my_shell)->prompt);
        //     (my_shell)->prompt = NULL;
        // }

        // if ((my_shell)->env != NULL) {
        //     // Assuming env is a NULL-terminated array of strings
        //     int i = 0;
        //     while ((my_shell)->env[i] != NULL) {
        //         free((my_shell)->env[i]); // Free each string
        //         i++;
        //     }
        //     free((my_shell)->env); // Free the array of strings
        //     // (my_shell)->env = NULL;
        // }

        // ... Free other dynamically allocated members if any ...

        // Now free the shell structure itself
}
*/