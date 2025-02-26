/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:50 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 20:08:44 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functs.h"
#include "print_arg_functs.h"

int	print_dec_args(va_list args)
{
	return (print_nbr(va_arg(args, int)));
}

int	print_int_args(va_list args)
{
	return (print_nbr(va_arg(args, int)));
}

int	print_unsigned_int_args(va_list args)
{
	return (print_nbr(va_arg(args, unsigned int)));
}

int	print_lowcase_hex_args(va_list args)
{
	return (print_hex(va_arg(args, unsigned long), HEX_LOWCASE_CHARSET));
}

int	print_uppercase_hex_args(va_list args)
{
	return (print_hex(va_arg(args, unsigned long), HEX_UPPCASE_CHARSET));
}
