/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_funct_mapping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:59 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/24 17:41:00 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_funct_mapping.h"
#include "token_util_functs.h"
#include "libft.h"

t_format_funct	*get_format_functs(void)
{
	static t_format_funct	token_functs[] = {
	{"%c", print_char},
	{"%s", print_str},
	{"%p", print_ptr},
	{"%d", print_dec},
	{"%i", print_int},
	{"%u", print_unsigned_int},
	{"%x", print_lowcase_hex},
	{"%X", print_uppercase_hex},
	{"%%", print_percentage},
	{NULL, NULL}
	};

	return (token_functs);
}

t_funct	get_funct_from_format(const char *format)
{
	int				i;
	t_format_funct	*functs;

	i = 0;
	functs = get_format_functs();
	while (functs[i].format != NULL)
	{
		if (ft_strncmp(functs[i].format, format,
				ft_strlen(functs[i].format)) == 0)
		{
			return (functs[i].funct);
		}
		i++;
	}
	return (NULL);
}
