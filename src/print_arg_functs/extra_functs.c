/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:33 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 01:52:37 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functs.h"
#include "symbols_config.h"

#include "print_functs.h"

int	print_percentage_args(va_list args)
{
	return (print_char(PPERCENTAGE_SYMBOL));
}

int	print_ptr_args(va_list args)
{
	int	len;

	len = print_str(POINTER_SYMBOL);
	len += print_hex(va_arg(args, unsigned long), HEX_LOWCASE_CHARSET);
	return (len);
}
