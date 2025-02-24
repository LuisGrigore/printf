/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:29:34 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:35:37 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "symbols_config.h"
#include "format_factory.h"
#include "libft.h"
#include "file_desc_config.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		length;
	char	*str;

	va_start(args, format);
	i = 0;
	length = 0;
	str = (char *)format;
	while (format[i])
	{
		if (format[i] == FORMAT_CHAR)
		{
			length += format_factory(&str[i], args);
			i++;
		}
		else
			ft_putchar_fd(format[i], STDOUT_FD);
		length++;
		i++;
	}
	va_end(args);
	return (length);
}
