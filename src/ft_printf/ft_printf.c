/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:29:34 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 01:55:33 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "symbols_config.h"
#include "format_funct_mapping.h"
#include "libft.h"
#include "file_desc_config.h"
#include "print_functs.h"

static int	print_format(const char *format_str, int *length, va_list args)
{
	char	*format;
	t_funct	funct;

	format = format_factory((char *)format_str);
	if (format)
	{
		funct = funct_factory(format);
		*length += funct(args);
	}
	return (ft_strlen(format));
}

static int	print_one_char(const char *format_str, int *length)
{
	*length += print_char(*format_str);
	return (1);
}

static int	print(char const *format_str, va_list args, int *length)
{
	char	*format;

	if (*format_str == FORMAT_CHAR)
	{
		return (print_format(format_str, length, args));
	}
	return (print_one_char(format_str, length));
}

int	ft_printf(char const *format_str, ...)
{
	va_list	args;
	int		length;

	va_start(args, format_str);
	length = 0;
	while (*format_str)
	{
		format_str += print(format_str, args, &length);
	}
	va_end(args);
	return (length);
}
