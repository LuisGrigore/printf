/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:55:39 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/25 18:41:06 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_char.h"

int	print_str(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
	while(*str)
	{
		length += print_char(*str);
		str++;
	}
	return (length);
}
