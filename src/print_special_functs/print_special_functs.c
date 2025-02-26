/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_special_functs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:29:21 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 19:56:36 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_SPECIAL_FUNCTS_H
# define PRINT_SPECIAL_FUNCTS_H

# include "print_special_functs.h"
# include "print_functs.h"
# include "symbols_config.h"

int	print_percentage(void)
{
	return (print_char(PPERCENTAGE_SYMBOL));
}

#endif
