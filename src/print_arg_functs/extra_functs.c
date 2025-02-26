/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:33 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 21:21:46 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_arg_functs.h"
#include "symbols_config.h"
#include "print_functs.h"

static int	ptr_null(void *ptr)
{
	int	len;

	if (!ptr)
		return (print_str(NULL_PTR_SYMBOL));
	len = print_str(POINTER_SYMBOL);
	len += print_ptr((uintptr_t) ptr);
	return (len);
}

int	print_ptr_args(va_list args)
{
	return (ptr_null(va_arg(args, void *)));
}
