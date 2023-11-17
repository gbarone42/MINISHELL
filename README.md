# 🚀 MINISHELL RESOURCES 🚀

## Contents

1. [🛠️ External Functions](#external-functions)

    - [🔧 Termios Functions](#termios-functions)
        1. [🔒 tcsetattr](#tcsetattr)
        2. [🔓 tcgetattr](#tcgetattr)

    - [📜 Readline Functions](#readline-functions)
        1. [🚀 readline](#readline)
        2. [🧹 rl_clear_history](#rl_clear_history)
        3. [🎉 rl_on_new_line](#rl_on_new_line)
        4. [✨ rl_replace_line](#rl_replace_line)
        5. [🔄 rl_redisplay](#rl_redisplay)
        6. [📚 add_history](#add_history)

2. [🧰 System Functions](#system-functions)

    - [💾 Memory Allocation](#memory-allocation)
        1. [📝 printf](#printf)
        2. [💼 malloc](#malloc)
        3. [🗑️ free](#free)

    3- [📥 Input/Output](#input-output)
        4. [📝 write](#write)
        5. [🔍 access](#access)
        6. [🔓 open](#open)
        7. [📖 read](#read)
        8. [🔒 close](#close)

    4- [🔄 Process Management](#process-management)
        9. [🔄 fork](#fork)
        10. [⌛ wait](#wait)
        11. [⌛ waitpid](#waitpid)
        12. [⌛ wait3](#wait3)
        13. [⌛ wait4](#wait4)
        14. [🔔 signal](#signal)
        15. [🚦 sigaction](#sigaction)
        16. [🚦 sigemptyset](#sigemptyset)
        17. [🚦 sigaddset](#sigaddset)
        18. [🔫 kill](#kill)
        19. [⛔ exit](#exit)

    5- [📁 File and Directory Management](#file-and-directory-management)
        20. [📂 getcwd](#getcwd)
        21. [📁 chdir](#chdir)
        22. [📊 stat](#stat)
        23. [📊 lstat](#lstat)
        24. [📊 fstat](#fstat)
        25. [🚮 unlink](#unlink)
        26. [💼 execve](#execve)

    6- [🔄 Process Duplication](#process-duplication)
        27. [🔀 dup](#dup)
        28. [🔀 dup2](#dup2)
        29. [🔧 pipe](#pipe)

    7- [📂 Directory Handling](#directory-handling)
        30. [🚪 opendir](#opendir)
        31. [📖 readdir](#readdir)
        32. [🚪 closedir](#closedir)

    8- [📚 Error Handling](#error-handling)
        33. [🚨 strerror](#strerror)
        34. [🚨 perror](#perror)

    9- [🔄 Terminal I/O](#terminal-io)
        35. [🔍 isatty](#isatty)
        36. [📛 ttyname](#ttyname)
        37. [📛 ttyslot](#ttyslot)
        38. [🔧 ioctl](#ioctl)

    10- [🌐 Environment Variables](#environment-variables)
        39. [🔄 getenv](#getenv)

    11- [🔧 Termcap Functions](#termcap-functions)
        40. [🔒 tgetent](#tgetent)
        41. [🔒 tgetflag](#tgetflag)
        42. [🔢 tgetnum](#tgetnum)
        43. [📚 tgetstr](#tgetstr)
        44. [📚 tgoto](#tgoto)
        45. [🔄 tputs](#tputs)
## 1. External Functions

### Termios Functions

In Unix-like operating systems, termios functions play a crucial role in managing terminal I/O settings. They allow you to configure various parameters of the terminal device, including baud rate, character size, and control flags.

#### `🔒 tcsetattr(int fd, int optional_actions, const struct termios *termios_p)`

The `tcsetattr` function is used to set the terminal attributes. It enables you to modify the terminal's behavior according to your requirements.

#### `🔓 tcgetattr(int fd, struct termios *termios_p)`

On the other hand, the `tcgetattr` function is used to get the current terminal attributes. This is useful when you want to retrieve the existing settings before making any modifications.

### Readline Functions

Readline functions are essential for interactive command-line interfaces, providing features like line editing and command history.

#### `🚀 readline(const char *prompt)`

This function reads a line from the user, facilitating interactive input in command-line applications.

#### `🧹 rl_clear_history(void)`

Clears the history list maintained by the Readline library. The history list typically contains previously entered command lines.

#### `🎉 rl_on_new_line(void)`

Notifies the Readline library that the cursor has moved to a new line. Useful for handling actions triggered by a new line in the input.

#### `✨ rl_replace_line(const char *text, int clear_undo)`

Replaces the contents of the current input line with the specified text. Useful for dynamic updates to the input line based on user actions or commands.

#### `🔄 rl_redisplay(void)`

Forces a redisplay of the current input line. Useful for updating the visual representation of the input line, especially after using rl_replace_line.

#### `📚 add_history(const char *string)`

Adds a line to the history list. Typically called after successfully processing a user command to store it in the history for later retrieval.

## 2. System Functions

### Memory Allocation

#### `📝 printf(const char *format, ...)`

Prints formatted output to the standard output.

#### `💼 malloc(size_t size)`

Allocates a specified number of bytes of memory.

#### `🗑️ free(void *ptr)`

Frees a block of memory previously allocated by malloc.

### Input/Output

#### `📝 write(int fd, const void *buf, size_t count)`

Writes data to a file descriptor.

#### `🔍 access(const char *pathname, int mode)`

Checks whether a file or directory can be accessed.

#### `🔓 open(const char *pathname, int flags, mode_t mode)`

Opens a file or creates a new one.

#### `📖 read(int fd, void *buf, size_t count)`

Reads data from a file descriptor into a buffer.

#### `🔒 close(int fd)`

Closes a file descriptor.

### Process Management

#### `🔄 fork(void)`

Creates a new process by duplicating the calling process.

#### `⌛ wait(int *status)`

Waits for any child process to exit.

#### `⌛ waitpid(pid_t pid, int *status, int options)`

Waits for a specific child process to exit.

#### `⌛ wait3(int *status, int options, struct rusage *rusage)`

Waits for any child process to exit, providing more information.

#### `⌛ wait4(pid_t pid, int *status, int options, struct rusage *rusage)`

Waits for a specific child process to exit, providing more information.

#### `🔔 signal(int signum, void (*handler)(int))`

Sets a function to handle a specific signal.

#### `🚦 sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)`

Sets a function to handle a signal with more control.

#### `🚦 sigemptyset(sigset_t *set)`

Initializes an empty signal set.

#### `🚦 sigaddset(sigset_t *set, int signum)`

Adds a signal to a signal set.

#### `🔫 kill(pid_t pid, int sig)`

Sends a signal to a process or a group of processes.

#### `⛔ exit(int status)`

Exits the calling process with a specified status.

### File and Directory Management

#### `📂 getcwd(char *buf, size_t size)`

Gets the current working directory.

#### `📁 chdir(const char *path)`

Changes the current working directory.

#### `📊 stat(const char *pathname, struct stat *statbuf)`

Gets file status.

#### `📊 lstat(const char *pathname, struct stat *statbuf)`

Gets symbolic link status.

#### `📊 fstat(int fd, struct stat *statbuf)`

Gets file status for a file descriptor.

#### `🚮 unlink(const char *pathname)`

Removes a specified file from the file system.

#### `💼 execve(const char *pathname, char *const argv[], char *const envp[])`

Executes a program.

### Process Duplication

#### `🔀 dup(int oldfd)`

Duplicates a file descriptor.

#### `🔀 dup2(int oldfd, int newfd)`

Duplicates a file descriptor to a specified descriptor.

#### `🔧 pipe(int pipefd[2])`

Creates a pipe, a unidirectional communication channel.

### Directory Handling

#### `🚪 opendir(const char *name)`

Opens a directory stream.

#### `📖 readdir(DIR *dirp)`

Reads a directory stream.

#### `🚪 closedir(DIR *dirp)`

Closes a directory stream.

### Error Handling

#### `🚨 strerror(int errnum)`

Returns a pointer to the textual representation of the current errno value.

#### `🚨 perror(const char *s)`

Prints a description for the last error that occurred.

### Terminal I/O

#### `🔍 isatty(int fd)`

Checks if a file descriptor refers to a terminal.

#### `📛 ttyname(int fd)`

Returns the name of the terminal connected to the given file descriptor.

#### `📛 ttyslot(void)`

Returns the slot number of the file associated with the current input.

#### `🔧 ioctl(int fd, unsigned long request, ...)`

Performs device control operations.

### Environment Variables

#### `🔄 getenv(const char *name)`

Gets the value of an environment variable.

### Termcap Functions

#### `🔒 tgetent(char *bp, const char *name)`

Initializes the termcap database.

#### `🔒 tgetflag(const char *id)`

Gets the value of a termcap capability as a boolean.

#### `🔢 tgetnum(const char *id)`

Gets the value of a termcap capability as an integer.

#### `📚 tgetstr(const char *id, char **area)`

Gets the value of a termcap capability as a string.

#### `📚 tgoto(const char *cm, int col, int row)`

Instantiates a cursor motion termcap string.

#### `🔄 tputs(const char *str, int affcnt, int (*putc)(int))`

Sends a termcap string to the terminal.
