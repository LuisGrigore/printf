/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util_extra_functs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:33 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:45:42 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_util_functs.h"
#include "puthex_with_charset.h"
#include "file_desc_config.h"
#include "libft.h"

int	print_percentage(va_list args)
{
	ft_putchar_fd(PPERCENTAGE_SYMBOL, STDOUT_FD);
	return (1);
}

int	print_ptr(va_list args)
{
	int	len;

	len = 0;
	ft_putstr_fd(POINTER_SYMBOL, STDOUT_FD);
	len += ft_strlen(POINTER_SYMBOL);
	len += puhex_with_charset(va_arg(args, unsigned long),
			STDOUT_FD, HEX_LOWCASE_CHARSET);
	return (len);
}
