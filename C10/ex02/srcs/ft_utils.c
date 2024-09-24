/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:52:23 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 14:09:01 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_str_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_number(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_custom_error(char *program_name, char *file_name)
{
	ft_print_error(basename(program_name));
	ft_print_error(": ");
	ft_print_error(file_name);
	ft_print_error(": ");
	ft_print_error(strerror(errno));
	ft_print_error("\n");
}

void	ft_custom_error_message(char *program_name, char *message, char *flag)
{
	ft_print_error(basename(program_name));
	ft_print_error(": ");
	ft_print_error(message);
	ft_print_error(" -- ");
	ft_print_error(flag);
	ft_print_error("\n");
}

void	ft_custom_error_message_2(char *program_name, char *message, char *flag)
{
	ft_print_error(basename(program_name));
	ft_print_error(": ");
	ft_print_error(message);
	ft_print_error(": \'");
	ft_print_error(flag);
	ft_print_error("\'");
	ft_print_error("\n");
}
