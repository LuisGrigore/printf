/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:41:29 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 18:51:38 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"

#include <unistd.h>

#include "symbols_config.h"
#include "max_values_config.h"
#include "file_desc_config.h"
#include "libft.h"
#include "reverse_buff.h"

int	print_char(char c)
{
	return (write(STDOUT_FD, &c, 1));
}

int	print_str(char *str)
{
	int	length;

	if (!str)
		return (print_str(NULL_STR_SYMBOL));
	length = 0;
	if (!str)
		return (0);
	while (*str)
	{
		length += print_char(*str);
		str++;
	}
	return (length);
}

int	print_ptr(uintptr_t num)
{
	char	buffer[16];
	int		i;

	i = 0;
	if (num == 0)
	{
		return (print_char(HEX_LOWCASE_CHARSET[0]));
	}
	while (num > 0)
	{
		buffer[i++] = HEX_LOWCASE_CHARSET[num % 16];
		num /= 16;
	}
	buffer[i] = '\0';
	reverse_buffer(buffer, i);
	return (print_str(buffer));
}

int	print_hex(unsigned int num, char *charset)
{
	char	buffer[16];
	int		i;

	i = 0;
	if (num == 0)
	{
		return (print_char(charset[0]));
	}
	while (num > 0)
	{
		buffer[i++] = charset[num % 16];
		num /= 16;
	}
	buffer[i] = '\0';
	reverse_buffer(buffer, i);
	return (print_str(buffer));
}

int	print_nbr(long num)
{
	unsigned int	i;
	long			n;

	i = 0;
	n = (long)num;
	if (n == INT_MIN_VAL)
		return (print_str(ft_itoa(INT_MIN_VAL)));
	if (n < 0)
	{
		i += print_char(NEGATIVE_SYMBOL);
		n = -n;
	}
	if (n > 9)
	{
		i += print_nbr(n / 10);
		i += print_char(n % 10 + '0');
	}
	else
		i += print_char(n + '0');
	return (i);
}
