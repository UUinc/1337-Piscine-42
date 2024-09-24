/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:07:08 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/17 22:23:09 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_memory.h"

void	ft_print_str(char *str, unsigned int size, unsigned int start)
{
	unsigned int	i;

	i = start;
	while (i < size)
	{
		if (str[i] <= 31 || (unsigned char)str[i] >= 127)
		{
			write(1, ".", 1);
			i++;
			continue ;
		}
		write(1, str + i, 1);
		i++;
	}
}

void	ft_print_hexa(char *addr_buff, long addr_value)
{
	static unsigned int	i;
	static unsigned int	count;

	if (addr_value < 16)
	{
		addr_buff[7 - count] = "0123456789abcdef"[addr_value];
		i = 0;
		while (i < 7 - count)
			addr_buff[i++] = '0';
		return ;
	}
	count++;
	ft_print_hexa(addr_buff, addr_value / 16);
	count--;
	addr_buff[7 - count] = "0123456789abcdef"[addr_value % 16];
}

void	ft_print_str_hexa(char *str, unsigned int size, int opt)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		write(1, &"0123456789abcdef"[(unsigned char)str[i] / 16], 1);
		write(1, &"0123456789abcdef"[(unsigned char)str[i] % 16], 1);
		if (i != size - 1)
			write(1, " ", 1);
		if (opt == 2 && (i == 7 || i == 15))
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "   ", 3);
		if (opt == 2 && (i == 7 || i == 15))
			write(1, " ", 1);
		i++;
	}
}

unsigned int	ft_print_memory(void *addr, unsigned int size,
					unsigned int ln, int opt)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	nbr;
	char			addr_buff[9];
	char			str[17];

	i = 0;
	len = size / 16;
	nbr = 16;
	while (i < len)
	{
		if (i == len)
			nbr = size % 16;
		ft_strlcpy(str, (char *) addr + 16 * i, nbr + 1);
		if (ft_handle_dub(str, &i))
			continue ;
		ft_strlcpy(g_last_str, (char *) addr + 16 * i, nbr + 1);
		ft_print_address(addr_buff, i, ln, opt);
		ft_print_data(str, nbr, opt);
		i++;
	}
	return (i + ln);
}

unsigned int	ft_print_memory_rest(void *addr, unsigned int size,
					unsigned int ln, int opt)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	nbr;
	char			addr_buff[9];
	char			str[17];

	i = 0;
	len = size / 16;
	nbr = 16;
	if (size > 0)
	{
		if (i == len)
			nbr = size % 16;
		ft_strlcpy(str, (char *) addr + 16 * i, nbr + 1);
		ft_print_address(addr_buff, 0, ln, opt);
		ft_print_data(str, nbr, opt);
		i++;
	}
	ft_print_hexa(addr_buff, (long)(16 * ln + size));
	ft_print_str(addr_buff, 8, 2 - opt);
	write(1, "\n", 1);
	return (0);
}
