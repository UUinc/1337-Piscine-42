/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:47:55 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 14:08:53 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_atoi.h"
#include "ft_utils.h"
#include "ft_tail.h"
#include "ft_read_input.h"

int	ft_args_check_2_args(int argc, char **argv)
{
	int	nbr;

	if (argc == 2)
	{
		if (!ft_is_str_number(argv[1] + 2))
		{
			ft_custom_error_message_2(argv[0], "invalid number of bytes",
				argv[1] + 2);
			return (-1);
		}
		if (argv[1][2] == '\0')
		{
			ft_custom_error_message(argv[0],
				"option requires an argument", "c");
			return (-1);
		}
		nbr = ft_atoi(argv[1] + 2);
		return (ft_read_input(nbr));
	}
	return (1);
}

int	ft_args_check_args(int argc, char **argv)
{
	int	nbr;

	if (!ft_is_str_number(argv[1] + 2))
	{
		ft_custom_error_message_2(argv[0], "invalid number of bytes",
			argv[1] + 2);
		return (-1);
	}
	if (argv[1][2] == '\0')
	{
		if (!ft_is_str_number(argv[2]))
		{
			ft_custom_error_message_2(argv[0], "invalid number of bytes",
				argv[2]);
			return (-1);
		}
		if (argc == 3)
			return (ft_read_input(ft_atoi(argv[2])));
		else
			return (ft_tail_files(argc, argv, 3, ft_atoi(argv[2])));
	}
	nbr = ft_atoi(argv[1] + 2);
	return (ft_tail_files(argc, argv, 2, nbr));
}

int	main(int argc, char **argv)
{
	int	error;

	error = ft_args_check_2_args(argc, argv);
	if (error < 0)
		return (1);
	error = ft_args_check_args(argc, argv);
	if (error < 0)
		return (2);
	return (0);
}
