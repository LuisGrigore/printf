/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:42 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 18:01:03 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTS_H
# define FUNCTS_H

# include <stdarg.h>

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