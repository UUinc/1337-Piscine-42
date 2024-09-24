/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:43:41 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 14:28:25 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_input.h"

void	ft_input_handler(char **buffer, int *i, char c, int option)
{
	if (c == '\n' && *i / 16 > 0)
	{
		*buffer = ft_print_hexdump(*buffer, option);
		*i = ft_strlen(*buffer);
	}
}

void	ft_buffer_handler(char **buffer, int option)
{
	if (*buffer != NULL)
	{
		*buffer = ft_print_hexdump(*buffer, option);
		free(*buffer);
	}
}

int	ft_read_input(int option)
{
	int		i;
	char	c;
	int		error;
	char	*buffer;
	int		index;

	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\0';
	i = 0;
	index = 0;
	while (1)
	{
		error = read(0, &c, 1);
		if (error <= 0)
			break ;
		buffer = realloc_str(buffer, 1);
		if (buffer == NULL)
			return (-1);
		buffer[i++] = c;
		buffer[i] = '\0';
		ft_input_handler(&buffer, &i, c, option);
	}
	ft_buffer_handler(&buffer, option);
	return (error);
}
