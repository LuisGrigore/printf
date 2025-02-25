/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:26 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/25 18:22:29 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functs.h"

#include "print_char.h"
#include "print_str.h"

int	print_char_args(va_list args)
{
	return (print_char(va_arg(args, int)));
}

int	print_str_args(va_list args)
{
	return (print_str(va_arg(args, char *)));
}
