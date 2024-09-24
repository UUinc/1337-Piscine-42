/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:23:41 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/14 17:55:21 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_to_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
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
