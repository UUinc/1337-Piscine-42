/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:30:33 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 13:35:32 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

void	ft_print_to_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_print_buffer(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		write(1, &str[i++], 1);
}

void	ft_print(char *str)
{
	ft_print_to_fd(str, 1);
}

void	ft_print_line(char *str)
{
	ft_print_to_fd(str, 1);
	ft_print_to_fd("\n", 1);
}

void	ft_print_error(char *str)
{
	ft_print_to_fd(str, 2);
}
