/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_functs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:42 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 20:12:41 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ARG_FUNCTS_H
# define PRINT_ARG_FUNCTS_H

# include <stdarg.h>

typedef int	(*t_funct)(va_list);

// Num Functs
int		print_dec_args(va_list args);
int		print_int_args(va_list args);
int		print_unsigned_int_args(va_list args);
// Extra Functs
int		print_lowcase_hex_args(va_list args);
int		print_uppercase_hex_args(va_list args);
int		print_ptr_args(va_list args);
// Chars Functs
int		print_str_args(va_list args);
int		print_char_args(va_list args);
#endif