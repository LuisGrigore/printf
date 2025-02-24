/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util_num_functs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:50 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 18:03:30 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_util_functs.h"
#include "puthex_with_charset.h"
#include "precisions_config.h"
#include "max_values_config.h"
#include "file_desc_config.h"
#include <stdio.h>
#include "libft.h"

static int	ft_putchar(int c)
{
	return (write (STDOUT_FD, &c, 1));
}


static int	ft_putnbr(int n)
{
	unsigned int	i;
	char *str;

	i = 0;
	if (n == INT_MIN_VAL)
	{
		str = ft_itoa(INT_MIN_VAL);
		return (write(STDOUT_FD, str, ft_strlen(str)));
	}
	if (n < 0)
	{
		i += ft_putchar(NEGATIVE_SYMBOL);
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar(n % 10 + '0');
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	print_dec(va_list args)
{
	return (ft_putnbr(va_arg(args, int)));
}

int	print_int(va_list args)
{
	ft_putnbr_fd(va_arg(args, int), STDOUT_FD);
	return (0);
}

int	print_unsigned_int(va_list args)
{
	unsigned int	unsigned_integer;
	char			buffer[12];
	int				i;

	unsigned_integer = va_arg(args, unsigned int);
	i = 11;
	buffer[i] = '\0';
	while (unsigned_integer > 0)
	{
		buffer[--i] = (unsigned_integer % 10) + '0';
		unsigned_integer /= 10;
	}
	write(STDOUT_FD, &buffer[i], 11 - i);
	return (ft_strlen(buffer));
}

int	print_lowcase_hex(va_list args)
{
	unsigned long	hex;

	hex = va_arg(args, unsigned long);
	return (puhex_with_charset(hex, STDOUT_FD, HEX_LOWCASE_CHARSET));
}

int	print_uppercase_hex(va_list args)
{
	unsigned long	hex;

	hex = va_arg(args, unsigned long);
	return (puhex_with_charset(hex, STDOUT_FD, HEX_UPPCASE_CHARSET));
}
