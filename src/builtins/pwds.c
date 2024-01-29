/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:57 by gbarone           #+#    #+#             */
/*   Updated: 2024/01/11 18:52:06 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_current_directory(void)
{
	char	current_directory[PATH_MAX];

	if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		printf("%s\n", current_directory);
	else
	{
		perror("getcwd");
	}
}
