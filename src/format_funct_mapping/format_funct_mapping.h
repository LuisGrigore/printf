/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_funct_mapping.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:29:09 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/26 20:13:01 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_FUNCT_MAPPING_H
# define FORMAT_FUNCT_MAPPING_H

# include <stdarg.h>
# include "print_arg_functs.h"
# include "print_special_functs.h"

typedef struct t_format_funct
{
	char	*format;
	t_funct	funct;
}	t_format_funct;

typedef struct t_special_format_funct
{
	char			*format;
	t_special_funct	funct;
}	t_special_format_funct;

t_funct					funct_factory(const char *format);
t_special_funct			special_funct_factory(const char *format);
t_format_funct			*get_format_functs(void);
char					*format_factory(char *str);
#endif