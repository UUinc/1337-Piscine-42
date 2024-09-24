/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:43:41 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/16 17:24:45 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_input.h"

void	ft_write_input(char *buffer, int nbr, int size)
{
	if (buffer != NULL)
	{
		if (nbr > size)
			write(1, buffer, size);
		else
			write(1, buffer + size - nbr, nbr);
		free(buffer);
	}
}

int	ft_read_input(int nbr)
{
	int		i;
	char	c;
	int		error;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\0';
	i = 0;
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
	}
	ft_write_input(buffer, nbr, i);
	return (error);
}
