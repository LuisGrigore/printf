/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util_chars_functs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:26 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:49:08 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_util_functs.h"
#include "file_desc_config.h"
#include "libft.h"

int	print_char(va_list args)
{
	ft_putchar_fd(va_arg(args, int), STDOUT_FD);
	return (1);
}

int	print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_fd(str, STDOUT_FD);
	return (ft_strlen(str));
}
