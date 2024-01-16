/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:44:18 by sdel-gra          #+#    #+#             */
/*   Updated: 2024/01/16 18:50:13 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../includes/libft.h"
# include "../libft/get_next_line.h"
# include "../includes/cmd.h"
# include "../includes/executor.h"
# include "../includes/builtin.h"

/*
	1 = '<'
	2 = '>'
	3 = '<<'
	4 = '>>'
*/

typedef struct s_mshell
{
	pid_t		pid_child;
	int			fd_pipe[2];
	int			tmp_fd;
	int			outfile;
	int			infile;
	char		**path;
	char		**cmd_path;
	char		**env;
	char		*cmd_args;
	int			exit_stat;
	t_cmd		*c_l;
}				t_mshell;
