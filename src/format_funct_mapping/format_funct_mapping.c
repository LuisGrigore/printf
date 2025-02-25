/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_funct_mapping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:59 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/25 18:39:15 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_funct_mapping.h"
#include "functs.h"
#include "libft.h"

t_format_funct	*get_format_functs(void)
{
	static t_format_funct	token_functs[] = {
	{"%c", print_char_args},
	{"%s", print_str_args},
	{"%p", print_ptr_args},
	{"%d", print_dec_args},
	{"%i", print_int_args},
	{"%u", print_unsigned_int_args},
	{"%x", print_lowcase_hex_args},
	{"%X", print_uppercase_hex_args},
	{"%%", print_percentage_args},
	{NULL, NULL}
	};

	return (token_functs);
}

t_funct	funct_factory(const char *format)
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

char	*format_factory(char *str)
{
	int				i;
	t_format_funct	*functs;

	i = 0;
	functs = get_format_functs();
	while (functs[i].format != NULL)
	{
		if (ft_strncmp(functs[i].format, str,
				ft_strlen(functs[i].format)) == 0)
		{
			return (functs[i].format);
		}
		i++;
	}
	return (NULL);
}
