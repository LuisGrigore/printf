/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_funct_mapping.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:29:09 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:44:15 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_FUNCT_MAPPING
# define FORMAT_FUNCT_MAPPING

# include <stdarg.h>

typedef int	(*t_funct)(va_list);

typedef struct	t_format_funct
{
	char	*format;
	t_funct	funct;
} t_format_funct;

t_funct			get_funct_from_format(const char *format);
t_format_funct	*get_format_functs(void);
#endif