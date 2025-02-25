/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:55:39 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/25 18:20:05 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_char.h"
#include "file_desc_config.h"
#include <unistd.h>

int	print_char(char c)
{
	return (write(STDOUT_FD, &c, 1));
}
