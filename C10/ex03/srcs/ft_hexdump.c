/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:11:11 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 22:25:38 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*ft_print_hexdump(char *buffer, int option)
{
	unsigned int	size;
	unsigned int	rest;

	size = ft_strlen(buffer);
	rest = size % 16;
	if (size < 16 && size >= 0)
	{
		g_line_c = ft_print_memory_rest(buffer, size, g_line_c, option);
		buffer = dealloc_str(buffer, size);
	}
	else if (size >= 16)
	{
		g_line_c = ft_print_memory(buffer, size - rest, g_line_c, option);
		buffer = dealloc_str(buffer, size - rest);
	}
	return (buffer);
}
