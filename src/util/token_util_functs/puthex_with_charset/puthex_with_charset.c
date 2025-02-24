/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_with_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:01 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:51:19 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puthex_with_charset.h"
#include "libft.h"

int	puhex_with_charset(unsigned long num, int fd, char *charset)
{
	char	buffer[16];
	char	temp;
	int		i;

	i = 0;
	if (num == 0)
	{
		ft_putchar_fd(charset[0], fd);
		return (1);
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
	ft_putstr_fd(buffer, fd);
	return (ft_strlen(buffer));
}
