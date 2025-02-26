/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:45:51 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 18:51:03 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_buff.h"

void	reverse_buffer(char *buffer, int length)
{
	char	temp;
	int		j;

	j = 0;
	while (j < length / 2)
	{
		temp = buffer[j];
		buffer[j] = buffer[length - j - 1];
		buffer[length - j - 1] = temp;
		j++;
	}
}
