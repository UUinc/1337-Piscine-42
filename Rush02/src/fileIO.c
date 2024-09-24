/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileIO.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:46:29 by ybouryal          #+#    #+#             */
/*   Updated: 2024/09/15 08:46:51 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
		g_error = IO_ERROR;
	return (fd);
}

int	read_file(int fd, char *buffer)
{
	int		i;
	char	c;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == 10)
			break ;
		buffer[i++] = c;
	}
	buffer[i] = '\0';
	return (i);
}
