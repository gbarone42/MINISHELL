void ft_minishell_simulator(t_shell *shell)
{
    t_pars  *command;

    while (1)
    {
        errno = 0;
        shell->input = readline(shell->prompt);

        if (shell->input == NULL)
        {
            if (errno)
            {
                write(STDERR_FILENO, "readline error: ", 17);
                continue;  // Optionally, decide whether to continue or exit
            }
            printf("\n");
            shell_exit(shell);
        }

        // Print the prompt
        printf("%s", shell->prompt);

        if (!ft_strncmp(shell->input, "exit", 5))
        {  
            shell_exit(shell);
        }

        add_history(shell->input);

        if (ft_isvalid(shell->input))
        {
            // Processing valid input
            shell_parser(shell, &command);
            // shell_executor(&command, shell); // Uncomment when implemented
        }

        free(shell->input);
    }
}