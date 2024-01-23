/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:17:48 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/04 23:43:51 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "printers/default_printers.h"
#include "specification.h"
#include "utils.h"

t_default_abstract_printer	*g_printer;
t_printing_specification	*g_specification;
va_list						g_ap;

static void	ft_specify_printer_with(char **conversion_specifier)
{
	char	read;

	read = **conversion_specifier;
	if (read == 'c')
		ft_new_char_printer(va_arg(g_ap, int));
	else if (read == 's')
		ft_new_string_printer(va_arg(g_ap, char *));
	else if (read == 'p')
		ft_new_pointer_printer(va_arg(g_ap, uintptr_t));
	else if (read == 'd' || read == 'i')
		ft_new_decimal_integer_printer(va_arg(g_ap, int));
	else if (read == 'u')
		ft_new_unsigned_printer(va_arg(g_ap, unsigned));
	else if (read == 'x')
		ft_new_min_hex_printer(va_arg(g_ap, unsigned));
	else if (read == 'X')
		ft_new_max_hex_printer(va_arg(g_ap, unsigned));
	else
		ft_new_percentage_printer('%');
	*conversion_specifier += 1;
}

static void	ft_init_printing_specification_with(char **subformat)
{
	char	read;

	ft_reset_specification();
	read = **subformat;
	while (!(read == 'c' || read == 's' || read == 'p' || read == 'd'
			|| read == 'i' || read == 'u' || read == 'x' || read == 'X'
			|| read == '%'))
	{
		if (read == '#')
			g_specification->flags |= 1;
		else if (read == '0')
			g_specification->flags |= 1 << 1;
		else if (read == '-')
			g_specification->flags |= 1 << 2;
		else if (read == ' ')
			g_specification->flags |= 1 << 3;
		else if (read == '+')
			g_specification->flags |= 1 << 4;
		else if (read == '.')
			g_specification->precision = ft_atoi_decorator(subformat, 1);
		else
			g_specification->width = ft_atoi_decorator(subformat, 0);
		read = *++*subformat;
	}
	ft_specify_printer_with(subformat);
}

static int	ft_free_and_return(int output)
{
	free(g_printer);
	free(g_specification);
	va_end(g_ap);
	return (output);
}

static int	ft_count_args(const char *format)
{
	int	args;

	args = 0;
	format = ft_strchr(format, '%');
	while (format++)
	{
		args++;
		format = ft_strchr(++format, '%');
	}
	return (args);
}

int	ft_printf(const char *format, ...)
{
	char	*subformat;
	int		output;
	int		args;

	va_start(g_ap, format);
	args = ft_count_args(format);
	g_printer = NULL;
	g_specification = NULL;
	if (args)
	{
		g_printer = ft_malloc_soul(sizeof(*g_printer));
		g_specification = ft_malloc_soul(sizeof(*g_specification));
	}
	output = 0;
	subformat = (char *) format;
	while (args--)
	{
		subformat = ft_strchr(subformat, '%') + 1;
		output += write(1, format, subformat - format - 1);
		ft_init_printing_specification_with(&subformat);
		output += g_printer->as_base.ft_print();
		format = subformat;
	}
	output += write(1, subformat, ft_strlen(subformat));
	return (ft_free_and_return(output));
}
