/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util_num_functs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:50 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:48:22 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_util_functs.h"
#include "puthex_with_charset.h"
#include "precisions_config.h"
#include "file_desc_config.h"
#include <stdio.h>
#include "libft.h"

int	print_dec(va_list args)
{
	int		len;
	double	num;
	int		integer;
	double	decimal;

	len = 0;
	num = va_arg(args, double);
	if (num < 0)
	{
		ft_putchar_fd(NEGATIVE_SYMBOL, STDOUT_FD);
		len++;
		num = -num;
	}
	integer = (int)num;
	decimal = num - integer;
	ft_putnbr_fd(integer, STDOUT_FD);
	ft_putchar_fd(FLOATING_POINT_SYMBOL, STDOUT_FD);
	len++;
	for (int i = 0; i < DOUBLE_PRECISION; i++)
	{
		decimal *= 10;
	}
	ft_putnbr_fd((int)(decimal + 0.5), STDOUT_FD);
	return (len);
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
