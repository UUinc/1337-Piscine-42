/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:40:09 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/16 18:16:22 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_write_header(char *file_name)
{
	ft_print("==> ");
	ft_print(file_name);
	ft_print_line(" <==");
}

int	ft_tail_file(char *file_name, int nbr)
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
	ft_write_input(buffer, nbr, size);
	return (ft_fclose(fd) == -1);
}

int	ft_tail_files(int argc, char **argv, int index, int nbr)
{
	int	mul_files;

	mul_files = argc - index - 1;
	while (index < argc)
	{
		if (mul_files)
			ft_write_header(argv[index]);
		if (ft_tail_file(argv[index], nbr))
		{
			ft_custom_error(argv[0], argv[index]);
			return (1);
		}
		if (index < argc - 1)
			ft_print_line("");
		index++;
	}
	return (0);
}
