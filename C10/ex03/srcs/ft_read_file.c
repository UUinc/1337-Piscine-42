/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:34:19 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 18:06:21 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_file.h"

int	ft_handle_errors(char **argv, int index,
	int error)
{
	if (error)
	{
		ft_custom_error(argv[0], argv[index - 1], "Bad file descriptor");
		return (1);
	}
	return (0);
}

int	ft_global_size(int argc, char **argv, int index)
{
	unsigned int	size;

	size = 0;
	while (index < argc)
	{
		size += ft_size(argv[index]);
		index++;
	}
	return (size);
}

char	*ft_malloc(int argc, char **argv, int index)
{
	unsigned int	size;
	char			*global_buffer;

	size = ft_global_size(argc, argv, index);
	global_buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (global_buffer == NULL)
		return (NULL);
	global_buffer[0] = '\0';
	return (global_buffer);
}

int	ft_read_file(char *file_name, char *global_buffer)
{
	int		fd;
	int		size;
	char	*buffer;

	fd = ft_fopen(file_name, "r");
	if (fd == -1)
		return (1);
	size = ft_size(file_name);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	size = ft_fread(fd, buffer, size);
	if (size == -1)
		return (1);
	buffer[size] = '\0';
	global_buffer = ft_strcat(global_buffer, buffer);
	free(buffer);
	return (ft_fclose(fd) == -1);
}

int	ft_read_files(int argc, char **argv, int index, int option)
{
	int				error;
	int				error_count;
	char			*global_buffer;

	global_buffer = ft_malloc(argc, argv, index);
	if (global_buffer == NULL)
		return (1);
	error = 1;
	error_count = index--;
	while (++index < argc)
	{
		if (ft_read_file(argv[index], global_buffer))
		{
			ft_error_message(argv[0], argv[index]);
			error_count++;
			if (errno != 2)
				error = 0;
		}
	}
	global_buffer = ft_print_hexdump(global_buffer, option);
	global_buffer = ft_print_hexdump(global_buffer, option);
	free(global_buffer);
	if (ft_handle_errors(argv, index, error && (index == error_count)))
		return (1);
	return (0);
}
