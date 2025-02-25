/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:28:11 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/25 18:21:15 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_hex.h"
#include "print_char.h"
#include "print_str.h"

int	print_hex(unsigned long num, char *charset)
{
	char	buffer[16];
	char	temp;
	int		i;

	i = 0;
	if (num == 0)
	{		
		return (print_char(charset[0]));
	}
	while (num > 0)
	{
		buffer[i++] = charset[num % 16];
		num /= 16;
	}
	buffer[i] = '\0';
	for (int j = 0; j < i / 2; j++)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
	return (print_str(buffer));
}
