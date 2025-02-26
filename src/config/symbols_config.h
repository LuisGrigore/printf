/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols_config.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:30:14 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 16:25:09 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLS_CONFIG_H
# define SYMBOLS_CONFIG_H

# ifndef NULL_STR_SYMBOL
#  define NULL_STR_SYMBOL "(null)"
# endif

# ifndef NULL_PTR_SYMBOL
#  define NULL_PTR_SYMBOL "(nil)"
# endif

# ifndef FORMAT_CHAR
#  define FORMAT_CHAR '%'
# endif

# ifndef HEX_UPPCASE_CHARSET
#  define HEX_UPPCASE_CHARSET "0123456789ABCDEF"
# endif

# ifndef HEX_LOWCASE_CHARSET
#  define HEX_LOWCASE_CHARSET "0123456789abcdef"
# endif

# ifndef PPERCENTAGE_SYMBOL
#  define PPERCENTAGE_SYMBOL '%'
# endif

# ifndef NEGATIVE_SYMBOL
#  define NEGATIVE_SYMBOL '-'
# endif

# ifndef POINTER_SYMBOL
#  define POINTER_SYMBOL "0x"
# endif

# ifndef FLOATING_POINT_SYMBOL
#  define FLOATING_POINT_SYMBOL '.'
# endif

#endif