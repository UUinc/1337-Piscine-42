/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:40:09 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 13:31:43 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	ft_display_file(char *file_name, char *buffer)
{
	int	fd;
	int	size;

	fd = ft_fopen(file_name, "r");
	if (fd == -1)
		return (1);
	size = ft_fread(fd, buffer, 30719);
	if (size == -1)
		return (1);
	ft_print_buffer(buffer, size);
	return (ft_fclose(fd) == -1);
}
