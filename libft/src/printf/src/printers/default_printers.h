/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_printers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/04/01 19:32:14 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_PRINTERS_H
# define DEFAULT_PRINTERS_H

# include "libft/libft.h"
# include "printf/printer.h"

// MACROS
# define BASE_D		10
# define BASE_X		16
# define DIGITS_D	"0123456789"
# define DIGITS_X	"0123456789abcdef"
# define DIGITS_XX	"0123456789ABCDEF"

// ABSTRACT DEFAULT PRINTERS

typedef struct default_printer
{
	t_printer	base;
	void		(*ft_init_string_len)(void);
	void		(*ft_build_string_right)(void);
	char		*sub;
	size_t		sub_len;
}	t_default_printer;

typedef struct hex_printer
{
	t_default_printer	default_base;
	char				ch;
}	t_hex_printer;

// UNION
typedef union abstract_printer
{
	t_printer			as_base;
	t_default_printer	as_default_printer;
	t_hex_printer		as_hex_printer;
}	t_default_abstract_printer;

// GLOBAL VARIABLES

extern t_default_abstract_printer	*g_printer;

// VARIOUS ABSTRACT PRINTERS CONSTRUCTORS

void	ft_new_default_printer(char *sub, size_t sub_len);
void	ft_new_default_num_printer(char *sub, size_t sub_len,
			void (*ft_num_build_string_right)(void));

// VARIOUS CONCRETE PRINTERS CONSTRUCTORS

void	ft_new_char_printer(char c);
void	ft_new_string_printer(char *s);
void	ft_new_pointer_printer(uintptr_t a);
void	ft_new_decimal_integer_printer(int di);
void	ft_new_unsigned_printer(unsigned int u);
void	ft_new_hex_printer(unsigned int x, char ch, char *base);
void	ft_new_min_hex_printer(unsigned int x);
void	ft_new_max_hex_printer(unsigned int x);
void	ft_new_percentage_printer(char c);

#endif
