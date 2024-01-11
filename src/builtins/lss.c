/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lss.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:52 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/10 16:33:22 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <time.h>

//no builtin
//here i use readdir(), its ookay
void print_current_directory_contents(void)
{
	DIR *dir = opendir(".");
	struct dirent *entry;

	if (dir == NULL)
	{
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}

	closedir(dir);
}
