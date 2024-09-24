/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:52:19 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 14:22:08 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_memory.h"

int	ft_handle_dub(char *str, unsigned int *i)
{
	if (g_last_str[0] != '\0')
	{
		if (ft_strcmp(str, g_last_str) != 0)
		{
			g_flag = 0;
		}
		if (g_flag)
		{
			(*i)++;
			return (1);
		}
		if (ft_strcmp(str, g_last_str) == 0)
		{
			write(1, "*\n", 2);
			g_flag = 1;
			(*i)++;
			return (1);
		}
	}
	return (0);
}

void	ft_print_sep(char *str, unsigned int nbr, int option)
{
	if (option == 2)
	{
		write(1, " |", 2);
		ft_print_str(str, nbr, 0);
		write(1, "|", 1);
	}
}

void	ft_print_address(char *addr_buff, unsigned int i,
			unsigned int ln, int opt)
{
	ft_print_hexa(addr_buff, (long)(16 * (i + ln)));
	ft_print_str(addr_buff, 8, 2 - opt);
	write(1, "  ", opt);
}

void	ft_print_data(char *str, unsigned int nbr, int opt)
{
	ft_print_str_hexa(str, nbr, opt);
	ft_print_sep(str, nbr, opt);
	write(1, "\n", 1);
}
