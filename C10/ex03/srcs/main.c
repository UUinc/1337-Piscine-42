/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:47:55 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 14:41:48 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_read_input.h"
#include "ft_read_file.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_read_input(1));
	if (ft_strcmp(argv[1], "-C") == 0)
	{
		if (argc == 2)
		{
			return (ft_read_input(2));
		}
		return (ft_read_files(argc, argv, 2, 2));
	}
	return (ft_read_files(argc, argv, 1, 1));
}
