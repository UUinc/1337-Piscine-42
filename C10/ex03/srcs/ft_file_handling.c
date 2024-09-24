/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:45:27 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 15:03:33 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_handling.h"

int	ft_fopen(char *file_name, char *open_mode)
{
	int	fd;

	fd = -1;
	if (ft_strcmp(open_mode, "w") == 0)
		fd = open(file_name, O_WRONLY);
	else if (ft_strcmp(open_mode, "r") == 0)
		fd = open(file_name, O_RDONLY);
	else if (ft_strcmp(open_mode, "a") == 0)
		fd = open(file_name, O_APPEND);
	else if (ft_strcmp(open_mode, "rw") == 0)
		fd = open(file_name, O_RDWR);
	return (fd);
}

int	ft_fclose(int fd)
{
	return (close(fd));
}

int	ft_fread(int fd, char *buffer, unsigned int size)
{
	int	sz;

	sz = read(fd, buffer, size);
	if (sz == -1)
		ft_fclose(fd);
	buffer[sz] = '\0';
	return (sz);
}

int	ft_fwrite(int fd, char *buffer, unsigned int size)
{
	int	sz;

	sz = write(fd, buffer, size);
	if (sz == -1)
		ft_fclose(fd);
	return (sz);
}

int	ft_size(char *file_name)
{
	int		fd;
	char	c;
	int		size;

	fd = ft_fopen(file_name, "r");
	if (fd == -1)
		return (0);
	size = 0;
	while (read(fd, &c, 1) > 0)
		size++;
	ft_fclose(fd);
	return (size);
}
