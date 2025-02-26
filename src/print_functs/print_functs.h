/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:49:48 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 18:32:43 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCTS_H
# define PRINT_FUNCTS_H

# include "symbols_config.h"
# include <stdint.h>

int	print_hex(unsigned int num, char *charset);
int	print_ptr(uintptr_t num);
int	print_char(char c);
int	print_str(char *str);
int	print_nbr(long n);

#endif