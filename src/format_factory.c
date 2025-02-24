/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:29:18 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:35:30 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_funct_mapping.h"
#include "format_factory.h"

int	format_factory(char *str, va_list args)
{
	t_funct	funct;

	funct = get_funct_from_format(str);
	if (!funct)
		return (0);
	return (funct(args));
}
