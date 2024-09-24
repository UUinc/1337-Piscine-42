/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:47:55 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 13:36:23 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_display_file.h"
#include "ft_read_print.h"
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_custom_error(char *program_name, char *file_name)
{
	ft_print_error(basename(program_name));
	ft_print_error(": ");
	ft_print_error(file_name);
	ft_print_error(": ");
	ft_print_error(strerror(errno));
	ft_print_error("\n");
}

int	main(int argc, char **argv)
{
	int		i;
	int		error;
	char	buffer[30720];

	if (argc < 2 || (argc == 2 && argv[1][0] == '-' && argv[1][1] == '\0'))
		return (ft_read_print());
	i = 1;
	while (i < argc)
	{
		error = ft_display_file(argv[i], buffer);
		if (error == 1)
		{
			ft_custom_error(argv[0], argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
