#include "../../include/minishell.h"

//here i use time(), localtime(), strftime(), no builtin

void print_current_time(void)
{
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    char time_str[50];
    strftime(time_str, sizeof(time_str), "%c", time_info);

    printf("%s\n", time_str);
}