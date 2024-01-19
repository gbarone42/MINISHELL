/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <sdel-gra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:53:43 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/02/13 18:56:53 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	il miglior modo per risolvere problemi di memoria e' usare buffer come
	 riempitivo quindi se dividi buffer ottieni sempre cose buone
	
	Else dentro al while
		// qua ci entro quando r == 0 || r == -1 
			// se r == 0 e non ho trovato \n nella riga, devo restituire tutto
			// se r == -1 free e set null
			// se ho finito il file devo liberare
			// se r == 0 buffer e' pieno e dobbiamo resituire quello 
			// se r == -1 libero e restituisco NULL
			// se r == 0  e buffer e' NULL restituisco NULL
*/
char	*get_next_line(int fd)
{
	char		*out;
	static char	*buffer;
	int			read_out;

	read_out = 1;
	while (ft_strchr_i(buffer, '\n') == -1)
	{
		out = ft_calloc_char(BUFFER_SIZE + 1);
		read_out = read(fd, out, BUFFER_SIZE);
		if (read_out > 0)
		{
			buffer = ft_strjoin_free(buffer, out);
			ft_free(&out);
		}
		else
		{
			out = ft_free(&out);
			if (read_out == -1 || (buffer && !buffer[0] && read_out == 0))
				return (ft_free(&buffer));
			return (ft_substr_split(&buffer, ft_strchr_i(buffer, '\0')));
		}
	}
	out = ft_substr_split(&buffer, ft_strchr_i(buffer, '\n') + 1);
	return (out);
}
