/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_p.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:07:57 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/10 16:17:30 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_P_H
# define GET_NEXT_LINE_P_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);
char	*ft_strchr_gnl(char *s, char input);
void	*ft_calloc_gnl(size_t nmemb, size_t size);

#endif
