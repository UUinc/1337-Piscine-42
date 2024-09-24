/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:27:17 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 13:27:24 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_display_file.h"

int	main(int argc, char **argv)
{
	char	buffer[30720];
	int		error;

	if (argc < 2)
	{
		ft_print_error("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_print_error("Too many arguments.\n");
		return (2);
	}
	error = ft_display_file(argv[1], buffer);
	if (error)
	{
		ft_print_error("Cannot read file.\n");
		return (3);
	}
	return (0);
}
