#include "../include/minishell.h"

int	g_exit = 0;


int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    t_shell my_shell;
    int output;

    memset(&my_shell, 0, sizeof(t_shell));
    printf("%sWelcome %s!%s\n", GREEN, getenv("USER"), CLR_RMV);
    output = ft_innit_shell(&my_shell, env);
    if (output != 0) {
        perror("Error initializing shell");
        exit(output);
    }
    ft_norm_signal();
    ft_minishell_simulator(&my_shell);

    return EXIT_SUCCESS;
}



//debug
//


// {
//   "version": "0.2.0",
//   "configurations": [
//     {
//       "name": "C/C++ Runner: Debug Session",
//       "type": "cppdbg",
//       "request": "launch",
//       "args": [],
//       "stopAtEntry": false,
//       "externalConsole": false,
//       "cwd": "/nfs/homes/everonel/Desktop/GBARONE/MINISHELL/src",
//       "program": "/nfs/homes/everonel/Desktop/GBARONE/MINISHELL/build/minishell",
//       "MIMode": "gdb",
//       "miDebuggerPath": "gdb",
//       "setupCommands": [
//         {
//           "description": "Enable pretty-printing for gdb",
//           "text": "-enable-pretty-printing",
//           "ignoreFailures": true
//         }
//       ]
//     }
//   ]
// }



// {
//   "version": "0.2.0",
//   "configurations": [
//     {
//       "name": "C/C++ Runner: Debug Session",
//       "type": "cppdbg",
//       "request": "launch",
//       "args": [],
//       "stopAtEntry": false,
//       "externalConsole": false,
//       "cwd": "/nfs/homes/everonel/Desktop/GBARONE/MINISHELL/src/builtins",
//       "program": "/nfs/homes/everonel/Desktop/GBARONE/MINISHELL/src/builtins/build/Debug/outDebug",
//       "MIMode": "gdb",
//       "miDebuggerPath": "gdb",
//       "setupCommands": [
//         {
//           "description": "Enable pretty-printing for gdb",
//           "text": "-enable-pretty-printing",
//           "ignoreFailures": true
//         }
//       ]
//     }
//   ]
// }